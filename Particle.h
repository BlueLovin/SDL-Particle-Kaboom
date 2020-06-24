#pragma once
#include <stdlib.h>
struct Particle
{
	double X, Y, direction, speed;
	double startX, startY;
	/*double Xspeed = 0.01 * (((2.0 * rand()) / RAND_MAX) - 1);
	double Yspeed = 0.01 * (((2.0 * rand()) / RAND_MAX) - 1);*/
	//the above values go from -1 to 1. we multiply by 0.01 so the speed is reduced 

	Particle();
	void update(int interval);
	double getX();
	double getY();
	//void randomizePos();
};

