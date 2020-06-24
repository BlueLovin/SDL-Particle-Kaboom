#include "Swarm.h"

Swarm::Swarm()
{
	Particles = new Particle[ParticleCount];
}

Swarm::~Swarm()
{
	delete[] Particles;
}

void Swarm::update(int elapsed)
{
	int interval = elapsed - lastTime;
	for (int i = 0; i < ParticleCount;i++) {
		Particles[i].update(interval);
	}
	lastTime = elapsed;
}
