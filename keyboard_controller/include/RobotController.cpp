#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdexcept>
#include <stdio.h>
#include "RobotController.h"
#include <string>

const Uint8 *keys = SDL_GetKeyboardState(NULL);

RobotController :: RobotController() {
	// Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) == 0) {

		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" ); //TODO
		}

		window = SDL_CreateWindow("V2Mini Controller", SDL_WINDOWPOS_UNDEFINED,
				SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

		if (window == NULL) {
			throw std::runtime_error("SDL failed to create window\n");

		} else {
			// Setup SDL window and load robot icon
			renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

			if (renderer == NULL) {
				throw std::runtime_error("SDL failed to render\n");
			}

			SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

			//Initialize PNG loading
			int imgFlags = IMG_INIT_PNG;
			if( !( IMG_Init( imgFlags ) & imgFlags ) )
			{
				printf( "SDL_image could not initialize! SDL_image Error:\n"); //todo
			}

			SDL_Surface* loadedSurface = IMG_Load("robo_icon.jpg");

			if( loadedSurface == NULL ) {
				//printf( "Unable to load image %s! SDL_image Error: \n"); //todo
			}

			texture = SDL_CreateTextureFromSurface( renderer, loadedSurface );

			if( texture == NULL )
			{
				//printf( "Unable to create texture from %s! SDL Error:\n"); //todo
			}

			SDL_FreeSurface( loadedSurface );

		}

	} else {
		throw std::runtime_error("SDL failed to initialize\n");
	}
}

RobotController ::~ RobotController() {
	//Deallocate SDL resources
	SDL_DestroyTexture(texture);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	window = NULL;
	renderer = NULL;
	texture = NULL;

	IMG_Quit();
	SDL_Quit();
}

int* RobotController :: getBaseCmds() {
	static int base_cmds[] = {0, 0, 0, 0};

	SDL_PumpEvents();

	if(keys[SDL_SCANCODE_ESCAPE]) {
		quit = true;
	}

	// Left & Right
	if (keys[SDL_SCANCODE_LEFT] != keys[SDL_SCANCODE_RIGHT]) {

		if (keys[SDL_SCANCODE_RIGHT] == 1) {
			icon_pos[0] = 1;

		} else {
			icon_pos[0] = -1;
		}

	} else {
		icon_pos[0] = 0;
	}

	// Forward & Back
	if (keys[SDL_SCANCODE_UP] != keys[SDL_SCANCODE_DOWN]) {

		if (keys[SDL_SCANCODE_UP] == 1) {
			icon_pos[1] = 1;

		} else {
			icon_pos[1] = -1;
		}

	} else {
		icon_pos[1] = 0;
	}

	// Angular CW & CCW
	if (keys[SDL_SCANCODE_Q] != keys[SDL_SCANCODE_W]) {

		if (keys[SDL_SCANCODE_Q] == 1) {
			icon_pos[2] = 1;

		} else {
			icon_pos[2] = -1;
		}

	} else {
		icon_pos[2] = 0;
	}

	printf("x= %i\n", icon_pos[0]);
	printf("y= %i\n", icon_pos[1]);
	printf("w= %i\n", icon_pos[2]);

	return base_cmds;
}

void RobotController :: reRenderImage() {

	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, texture, NULL, NULL);
	SDL_RenderPresent(renderer);
}

bool RobotController :: checkQuitStatus() {
	return quit;
}
