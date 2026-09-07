#include "SDL.h"
#include "SDL_image.h"

int IMG_isGIF(SDL_RWops *src)  { (void)src; return 0; }
int IMG_isLBM(SDL_RWops *src)  { (void)src; return 0; }
int IMG_isPCX(SDL_RWops *src)  { (void)src; return 0; }
int IMG_isPNM(SDL_RWops *src)  { (void)src; return 0; }
int IMG_isTIF(SDL_RWops *src)  { (void)src; return 0; }
int IMG_isWEBP(SDL_RWops *src) { (void)src; return 0; }
int IMG_isXCF(SDL_RWops *src)  { (void)src; return 0; }
int IMG_isXPM(SDL_RWops *src)  { (void)src; return 0; }
int IMG_isXV(SDL_RWops *src)   { (void)src; return 0; }

SDL_Surface *IMG_LoadGIF_RW(SDL_RWops *src)  { (void)src; return NULL; }
SDL_Surface *IMG_LoadLBM_RW(SDL_RWops *src)  { (void)src; return NULL; }
SDL_Surface *IMG_LoadPCX_RW(SDL_RWops *src)  { (void)src; return NULL; }
SDL_Surface *IMG_LoadPNM_RW(SDL_RWops *src)  { (void)src; return NULL; }
SDL_Surface *IMG_LoadTIF_RW(SDL_RWops *src)  { (void)src; return NULL; }
SDL_Surface *IMG_LoadWEBP_RW(SDL_RWops *src) { (void)src; return NULL; }
SDL_Surface *IMG_LoadXCF_RW(SDL_RWops *src)  { (void)src; return NULL; }
SDL_Surface *IMG_LoadXPM_RW(SDL_RWops *src)  { (void)src; return NULL; }
SDL_Surface *IMG_LoadXV_RW(SDL_RWops *src)   { (void)src; return NULL; }

void IMG_QuitTIF(void)  {}
void IMG_QuitWEBP(void) {}

int IMG_InitTIF(void)  { return -1; }
int IMG_InitWEBP(void) { return -1; }
