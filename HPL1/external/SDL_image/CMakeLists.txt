cmake_minimum_required (VERSION 3.5)
project (SDL_image)

# SDL_image for classic SDL 1.2 (not SDL2_image). Upstream deprecated this
# from Homebrew, so we build it ourselves from source
# (github.com/libsdl-org/SDL_image, SDL-1.2 branch) against Homebrew's
# SDL 1.2 + libjpeg + libpng/zlib.
#
# Only BMP/TGA/JPG/PNG format loaders are enabled (via -DLOAD_BMP etc) -
# these are the only formats HPL1's own bundled assets actually use.
# Each format's .c file guards its ENTIRE content behind its own
# LOAD_<FORMAT> macro, so compiling the other (disabled) format files
# here is harmless - they simply produce empty translation units.
#
# The engine's own code writes "#include <SDL/SDL_image.h>" (with the
# SDL/ prefix baked into the include path itself), so our own copy of
# the header is duplicated under a local SDL/ subdirectory here too,
# matching the same convention used for SDL_ttf.

find_package(PkgConfig REQUIRED)
pkg_check_modules(JPEG_FOR_IMG REQUIRED libjpeg)
pkg_check_modules(PNG_FOR_IMG REQUIRED libpng)
pkg_check_modules(SDL_FOR_IMG REQUIRED sdl)

add_library(SDL_image STATIC
	IMG.c
	IMG_bmp.c
	IMG_tga.c
	IMG_jpg.c
	IMG_png.c
	IMG_format_stubs.c
)

target_compile_definitions(SDL_image PRIVATE
	LOAD_BMP
	LOAD_TGA
	LOAD_JPG
	LOAD_PNG
	# On Apple platforms, IMG.c's own portable IMG_Load() (using our
	# libjpeg/libpng-based format loaders) is excluded by default in
	# favor of a separate, native ImageIO-based Objective-C backend
	# (IMG_ImageIO.m) that we don't compile - this forces the portable
	# C implementation to be used instead, matching the rest of our setup.
	SDL_IMAGE_USE_COMMON_BACKEND
)

target_include_directories(SDL_image PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}
	${JPEG_FOR_IMG_INCLUDE_DIRS}
	${PNG_FOR_IMG_INCLUDE_DIRS}
	${SDL_FOR_IMG_INCLUDE_DIRS}
)
foreach(_inc ${SDL_FOR_IMG_INCLUDE_DIRS})
	get_filename_component(_inc_parent ${_inc} DIRECTORY)
	target_include_directories(SDL_image PUBLIC ${_inc_parent})
endforeach()

target_link_libraries(SDL_image PUBLIC
	${JPEG_FOR_IMG_LIBRARIES}
	${PNG_FOR_IMG_LIBRARIES}
	${SDL_FOR_IMG_LIBRARIES}
)
