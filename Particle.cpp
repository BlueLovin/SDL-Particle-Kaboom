#include "Particle.h"
#include "Screen.h"
#include <math.h>

Particle::Particle() : X(0), Y(0)
{
	/*X = (2.0 * rand()/RAND_MAX) - 1;
	Y = (2.0 * rand()/RAND_MAX) - 1;*/
	direction = (2 * M_PI * rand())/RAND_MAX;
	speed = (0.001 * rand()) / RAND_MAX;
}

void Particle::update(int interval)
{
	double xSpeed = speed * cos(direction);
	double ySpeed = speed * sin(direction);
	
	X += xSpeed * interval; Y += ySpeed * interval;
	//remember: 1 = the end or bottom of the screen. 
}

			//below values are random from -1 to 1. We need to change them...
			//so we add one to change the range from 0 to 2, then multiply...
			//by HALF the screen width. So that 2 = the screen width, ...
			//and 1 equals half of the screen. and 0 is the beginning of the screen.
double Particle::getX()
{
	return (X + 1) *SCREENSIZE / 2;
}

double Particle::getY()
{
	return (Y + 1) *SCREENSIZE / 2;
}

//void Particle::randomizePos()
//{
//	this->X += (2.0 * rand() / RAND_MAX) - 1;
//	this->Y += (2.0 * rand() / RAND_MAX) - 1;
//}
