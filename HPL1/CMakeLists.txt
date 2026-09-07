cmake_minimum_required (VERSION 3.5)
project (HPL)

set(HPL_VERSION_MAJOR 1)
set(HPL_VERSION_MINOR 0)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(external/AngelScript)
add_subdirectory(external/Newton)
add_subdirectory(external/SDL_ttf)
add_subdirectory(external/SDL_image)
add_subdirectory(external/Cg2glsl)

include_directories(
	${CMAKE_CURRENT_SOURCE_DIR}/include
	${CMAKE_CURRENT_SOURCE_DIR}/../OALWrapper/include
	${CMAKE_CURRENT_SOURCE_DIR}/external/AngelScript/include
	${CMAKE_CURRENT_SOURCE_DIR}/external/Cg2glsl/include
	${CMAKE_CURRENT_SOURCE_DIR}/external/CgStub
)

file(GLOB_RECURSE all_sources
	${CMAKE_CURRENT_SOURCE_DIR}/sources/*.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/*.c
)

file(GLOB_RECURSE to_remove_all
	${CMAKE_CURRENT_SOURCE_DIR}/sources/*win32.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/*Video*Theora.cpp
)
list(REMOVE_ITEM all_sources ${to_remove_all})
list(REMOVE_DUPLICATES all_sources)

add_library(HPL STATIC ${all_sources})

target_link_libraries(HPL
	AngelScript
	Newton
	SDL_ttf
	SDL_image
	hlsl2glsl
)

find_package(PkgConfig REQUIRED)
pkg_check_modules(SDL REQUIRED sdl)
target_include_directories(HPL PUBLIC ${SDL_INCLUDE_DIRS})
foreach(_sdl_inc ${SDL_INCLUDE_DIRS})
	get_filename_component(_sdl_inc_parent ${_sdl_inc} DIRECTORY)
	target_include_directories(HPL PUBLIC ${_sdl_inc_parent})
endforeach()
target_link_libraries(HPL ${SDL_LIBRARIES})

find_package(FLTK REQUIRED)
target_include_directories(HPL PUBLIC ${FLTK_INCLUDE_DIR})
target_link_libraries(HPL ${FLTK_LIBRARIES})
