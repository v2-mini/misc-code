#ifndef __ROBOT_CONTROLLER_H
#define __ROBOT_CONTROLLER_H

#include <SDL2/SDL.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

class RobotController {

	private:
		bool quit = false;
		int icon_pos[3] = {0, 0, 0};
		SDL_Window* window = NULL;
		SDL_Surface* surface = NULL;
		SDL_Renderer* renderer = NULL;
		SDL_Texture* texture = NULL;
		SDL_Event event;

	public:
		RobotController();
		~RobotController();
		int* getBaseCmds();
		bool checkQuitStatus();
		void reRenderImage();
};

#endif
