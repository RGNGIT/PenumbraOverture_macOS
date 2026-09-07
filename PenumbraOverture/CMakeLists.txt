cmake_minimum_required (VERSION 3.5)
project(Overture)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# NOTE: unlike the original CMakeLists.txt (which tried to add_subdirectory
# the sibling HPL1Engine/OALWrapper projects, expecting an ../HPL1Engine
# folder name that doesn't match our actual ../HPL1 checkout, and would
# also conflict with those projects already being built standalone) -
# this build links directly against the already-built static libraries
# from HPL1's own build/ directory (../HPL1/build) and a standalone
# OALWrapper build (../OALWrapper/build), rather than re-configuring them
# as nested subprojects here.

set(HPL1_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/../HPL1)
set(HPL1_BUILD ${HPL1_ROOT}/build)
set(OALWRAPPER_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/../OALWrapper)
set(OALWRAPPER_BUILD ${OALWRAPPER_ROOT}/build)

include_directories(
	${HPL1_ROOT}/include
	${HPL1_ROOT}/external/AngelScript/include
	${HPL1_ROOT}/external/CgStub
	${OALWRAPPER_ROOT}/include
)

find_package(PkgConfig REQUIRED)
pkg_check_modules(SDL REQUIRED sdl)
# NOTE: sdl.pc traditionally lists both SDL and SDLmain as required
# libraries, but Homebrew's sdl formula doesn't actually provide a
# standalone libSDLmain - that functionality is expected to come from
# compiling SDLMain.m/.h directly into the app (which we already do, see
# below), so strip the dangling "SDLmain" reference out of the list
# pkg-config gives us before it gets passed to the linker.
list(REMOVE_ITEM SDL_LIBRARIES "SDLmain")
include_directories(${SDL_INCLUDE_DIRS})
foreach(_sdl_inc ${SDL_INCLUDE_DIRS})
	get_filename_component(_sdl_inc_parent ${_sdl_inc} DIRECTORY)
	include_directories(${_sdl_inc_parent})
endforeach()

set(CMAKE_EXECUTABLE_SUFFIX "")

file(GLOB all_sources ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

enable_language(OBJC)
list(APPEND all_sources ${CMAKE_CURRENT_SOURCE_DIR}/SDLMain.m)

add_executable(Overture ${all_sources})

set_target_properties(Overture PROPERTIES
	OUTPUT_NAME overture)

target_link_libraries(Overture
	${HPL1_BUILD}/libHPL.a
	${HPL1_BUILD}/external/AngelScript/libAngelScript.a
	${HPL1_BUILD}/external/Newton/libNewton.a
	${HPL1_BUILD}/external/SDL_ttf/libSDL_ttf.a
	${HPL1_BUILD}/external/SDL_image/libSDL_image.a
	${HPL1_BUILD}/external/Cg2glsl/libhlsl2glsl.a
	${OALWRAPPER_BUILD}/libOALWrapper.a
)

find_package(FLTK REQUIRED)
target_include_directories(Overture PUBLIC ${FLTK_INCLUDE_DIR})
target_link_libraries(Overture ${FLTK_LIBRARIES})

pkg_check_modules(OGG REQUIRED ogg)
pkg_check_modules(VORBIS REQUIRED vorbis)
pkg_check_modules(VORBISFILE REQUIRED vorbisfile)
pkg_check_modules(JPEG_LIB REQUIRED libjpeg)
pkg_check_modules(PNG_LIB REQUIRED libpng)
pkg_check_modules(FREETYPE_LIB REQUIRED freetype2)

target_link_directories(Overture PUBLIC
	${OGG_LIBRARY_DIRS}
	${VORBIS_LIBRARY_DIRS}
	${VORBISFILE_LIBRARY_DIRS}
	${JPEG_LIB_LIBRARY_DIRS}
	${PNG_LIB_LIBRARY_DIRS}
	${FREETYPE_LIB_LIBRARY_DIRS}
	${SDL_LIBRARY_DIRS}
)

target_link_libraries(Overture
	${OGG_LIBRARIES}
	${VORBIS_LIBRARIES}
	${VORBISFILE_LIBRARIES}
	${JPEG_LIB_LIBRARIES}
	${PNG_LIB_LIBRARIES}
	${FREETYPE_LIB_LIBRARIES}
	${SDL_LIBRARIES}
)

find_library(OPENAL_FRAMEWORK OpenAL REQUIRED)
find_library(OPENGL_FRAMEWORK OpenGL REQUIRED)
target_link_libraries(Overture ${OPENAL_FRAMEWORK} ${OPENGL_FRAMEWORK})

# NOTE: Cg/CgGL intentionally NOT linked - CgStub is header-only.
# NOTE: alut intentionally NOT linked - never actually used by this game's
# own source code (confirmed via grep), just vestigial from an old link line.
