#include <iostream>
#include <time.h>
#include "Screen.h"
#include "Particle.h"
#include "Swarm.h"

int main(int argc, char *argv[]) {
	
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		std::cout << "ERROR!\n" << SDL_GetError();

	Screen screen;
	Swarm swarm;
	Particle p;

	if (screen.init() == false)//INITIALIZE SCREEN!
		std::cout << "error!\n";

	srand(time(NULL));//MAKE SURE RANDOM IS ACTUALLY RANDOM!
	while (1) {
		//GAME LOOP

		//MATHEMATICS! NOOOOOO
		int var = SDL_GetTicks();
		unsigned char red = (unsigned char)((1 + cos(var * 0.001)) * 128);
		unsigned char green = (unsigned char)((1 + sin(var * 0.002)) * 128);
		unsigned char blue = (unsigned char)((1 + sin(var * 0.005)) * 128);
		//////////////////////

		const Particle *const pParticles = swarm.getParticles();
		swarm.update(var);
		for (int i = 0; i < Swarm::ParticleCount; i++) {

			Particle _particle = pParticles[i];

			//_particle.randomizePos();
			double x = _particle.getX();
			double y = _particle.getY();

			screen.setPixel(x, y, red, green, blue);
		}
		screen.update();
		screen.clear();
		if (screen.userQuit() == false)//check for a user 'quit'
			break;
		
	}
	screen.cleanup();
	return EXIT_SUCCESS;
}