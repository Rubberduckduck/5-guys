#include "pch.hpp"
#include "ParticleSystem.hpp"

namespace ownProject {

	float& particle::getLifetime()
	{
		return lifetime;
	}

	sf::Vector2f& particle::getVelocity() {
		return velocity;
	}

	float particle::getLifetime() const {
		return lifetime;
	}

	sf::Vector2f particle::getVelocity() const {
		return velocity;
	}


	particleSystem::particleSystem(unsigned int particlesCount)
		: vertices(sf::Points, particlesCount), particles(particlesCount), particlesDuration{ PARTICLE_DURATION }, pos{0.f,0.f}
	{
	}

	void particleSystem::setPos(sf::Vector2f toSet)
	{
		pos = toSet;
	}

	void particleSystem::update(float dt)
	{
		// Dt is in seconds, lifetime is in seconds as well

		// Have to use old for loop, one particle == one elem in vertex array
		for (size_t i = 0; i < particles.size(); i++)
		{
			// Update each particle lifetime
			particle& elem = particles[i];
			elem.getLifetime() -= dt;

			// If particle dead (lifetime == 0), resparn
			if (elem.getLifetime() <= 0)
			{
				resetParticle(i);
			}
			
			// Update position of corresponding vertex
			vertices[i].position += elem.getVelocity() * dt;

			// Update alpha of (transparency) of particle according to each particle's lifetime

			// 1 millisecond == 1/000 second, 1 second = 1000 milisecond
			float ratio = elem.getLifetime() / particlesDuration;
			// a is alpha
			vertices[i].color.a = static_cast<sf::Uint8>(ratio * 255);

		}
	}

	void particleSystem::resetParticle(size_t index)
	{
		// Give random velocity and lifetime to particle
		float angle = (std::rand() % 360) * static_cast<float>(M_PI) / 180.f;
		float velo = (std::rand() % 75) + 75.f;
		particles[index].getVelocity() = sf::Vector2f(std::cos(angle) * velo, std::sin(angle) * velo);
		// 1 millisecond == 1/000 second, 1 second = 1000 milisecond
		particles[index].getLifetime() = sf::milliseconds((std::rand() % 2000) + 1000).asSeconds();

		// Reset pos of corresponding vertex
		vertices[index].position = pos;

	}

	void particleSystem::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{

		// apply the transform
		states.transform *= getTransform();

		// our particles don't use a texture
		states.texture = NULL;

		// draw the vertex array
		target.draw(vertices, states);

	}



}