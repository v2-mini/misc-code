#include "../include/RobotController.h"


int main(int argc, char ** argv) {

	RobotController controller;

	while(!controller.checkQuitStatus()) {

		controller.getBaseCmds();
		controller.reRenderImage();

	}

	return 0;
}
