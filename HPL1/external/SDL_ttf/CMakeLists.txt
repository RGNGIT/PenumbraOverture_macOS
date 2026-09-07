cmake_minimum_required (VERSION 3.5)
project (SDL_ttf)

# SDL_ttf for classic SDL 1.2 (not SDL2_ttf). Upstream deprecated this
# since 2013 and Homebrew no longer packages it, so we build it ourselves
# from source (github.com/sailfishos/libsdl-ttf, SDL-1.2 branch) against
# Homebrew's SDL 1.2 + FreeType.
#
# The engine's own code writes "#include <SDL/SDL_ttf.h>" (with the SDL/
# prefix baked into the include path itself), so our own copy of the
# header is duplicated under a local SDL/ subdirectory here too, and we
# expose THIS directory (the parent of that SDL/ subfolder) publicly.

find_package(PkgConfig REQUIRED)
pkg_check_modules(FREETYPE2 REQUIRED freetype2)
pkg_check_modules(SDL_FOR_TTF REQUIRED sdl)

add_library(SDL_ttf STATIC
	SDL_ttf.c
)

target_include_directories(SDL_ttf PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}
	${FREETYPE2_INCLUDE_DIRS}
	${SDL_FOR_TTF_INCLUDE_DIRS}
)
foreach(_inc ${SDL_FOR_TTF_INCLUDE_DIRS})
	get_filename_component(_inc_parent ${_inc} DIRECTORY)
	target_include_directories(SDL_ttf PUBLIC ${_inc_parent})
endforeach()

target_link_libraries(SDL_ttf PUBLIC ${FREETYPE2_LIBRARIES} ${SDL_FOR_TTF_LIBRARIES})
