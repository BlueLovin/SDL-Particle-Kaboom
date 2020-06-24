#pragma once
#include "Particle.h"
class Swarm
{
public:
	Swarm();
	~Swarm();
	void update(int elapsed);
	const Particle *const getParticles() { return Particles; }//getter
	const static int ParticleCount = 5000;
private:
	Particle *Particles;
	int lastTime;
};