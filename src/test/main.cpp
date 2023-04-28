/**
 * @file main.cpp
 * @author Will Brandon (brandon.w@northeastern.edu)
 * @brief 
 * @version 1.0
 * @date 4-19-2023
 * 
 * @copyright Copyright (c) 2023
 */

#include <SDL2/SDL.h>
#include <SDL2/SDL_syswm.h>
#include <thread>
#include "../../libs/bgfx/include/bgfx/bgfx.h"
#include "../../libs/bgfx/include/bgfx/platform.h"
#include "../../libs/bx/include/bx/platform.h"
#include <stdio.h>
#include <iostream>

/* Sets constants */
#define WIDTH 800
#define HEIGHT 600
#define DELAY 3000

using namespace std;

int main(int argc, char **argv)
{
  /* Initialises data */
  SDL_Window *window = NULL;

  SDL_Surface* screenSurface = NULL;
  
  /*
  * Initialises the SDL video subsystem (as well as the events subsystem).
  * Returns 0 on success or a negative error code on failure using SDL_GetError().
  */
  if (SDL_Init(0) != 0) {
    fprintf(stderr, "SDL failed to initialise: %s\n", SDL_GetError());
    return 1;
  }

  /* Creates a SDL window */
  window = SDL_CreateWindow(
    "SDL Example", /* Title of the SDL window */
		SDL_WINDOWPOS_UNDEFINED, /* Position x of the window */
		SDL_WINDOWPOS_UNDEFINED, /* Position y of the window */
		WIDTH, /* Width of the window in pixels */
		HEIGHT, /* Height of the window in pixels */
		SDL_INIT_VIDEO
  ); /* Additional flag(s) */
  
  /* Checks if window has been created; if not, exits program */
  if (window == NULL) {
    fprintf(stderr, "SDL window failed to initialise: %s\n", SDL_GetError());
    return 1;
  }

  SDL_SysWMinfo sdl_window_info;
  SDL_VERSION(&sdl_window_info.version)

  if (!SDL_GetWindowWMInfo(window, &sdl_window_info))
  {
    fprintf(stderr, "SDL window failed to get info: %s\n", SDL_GetError());
    return 1;
  }
  
  bgfx::PlatformData pd;
#if BX_PLATFORM_LINUX || BX_PLATFORM_BSD
    cout << "LINUX\n";
    pd.ndt = sdl_window_info.info.x11.display;
    pd.nwh = (void*)(uintptr_t)sdl_window_info.info.x11.window;
#elif BX_PLATFORM_OSX
    cout << "OSX\n";
    pd.ndt = NULL;
    pd.nwh = sdl_window_info.info.cocoa.window;
#elif BX_PLATFORM_WINDOWS
    cout << "WINDOWS\n";
    pd.ndt = NULL;
    pd.nwh = sdl_window_info.info.win.window;
#elif BX_PLATFORM_STEAMLINK
    cout << "STEAMLINK\n";
    pd.ndt = sdl_window_info.info.vivante.display;
    pd.nwh = sdl_window_info.info.vivante.window;
#else
    cout << "NOPE\n";
#endif // BX_PLATFORM_

  pd.context = NULL;
  pd.backBuffer = NULL;
  pd.backBufferDS = NULL;
  bgfx::setPlatformData(pd);

  bgfx::renderFrame();

  //bgfx::setPlatformData(pd);
  
  //bgfx::Init bgfxInit;
  //bgfxInit.type = bgfx::RendererType::Count; // Automatically choose a renderer.
  //bgfxInit.resolution.width = WIDTH;
  //bgfxInit.resolution.height = HEIGHT;
  //bgfxInit.resolution.reset = BGFX_RESET_VSYNC;
  //bgfx::init(bgfxInit);

  //bgfx::setViewClear(0, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH, 0x443355FF, 1.0f, 0);
  //bgfx::setViewRect(0, 0, 0, WIDTH, HEIGHT);

  //screenSurface = SDL_GetWindowSurface(window);
  //SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));
  //SDL_UpdateWindowSurface(window);

  SDL_SetWindowResizable(window, SDL_TRUE);

  /* Pauses all SDL subsystems for a variable amount of milliseconds */
  //SDL_Delay(DELAY);

  SDL_Event e;
  bool quit = false;
  while (!quit){

      //bgfx::frame();

      while (SDL_PollEvent(&e)){
          if (e.type == SDL_QUIT){
              quit = true;
          }
          if (e.type == SDL_KEYDOWN){
              //quit = true;
          }
          if (e.type == SDL_MOUSEBUTTONDOWN){
              //quit = true;
          }
      }
  }

  /* Frees memory */
  SDL_DestroyWindow(window);
  
  /* Shuts down all SDL subsystems */
  SDL_Quit();
  
  return 0;
}
