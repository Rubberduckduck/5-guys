#include "pch.hpp"
#include "ParticleSystem.hpp"

namespace ownProject {

	particle::particle() {}

	particle::particle(sf::Vector2i setScale, sf::Vector2f setPos, float setLifetime, sf::Vector2f setVelocity)
		: scale{ setScale }, pos{ setPos }, lifetime{ setLifetime }, velocity{ setVelocity } {}

	sf::Vector2i& particle::getScale()
	{
		return scale;
	}

	sf::Vector2f& particle::getPos()
	{
		return pos;
	}

	float& particle::getLifetime()
	{
		return lifetime;
	}

	sf::Vector2f& particle::getVelocity()
	{
		return velocity;
	}

	sf::Vector2i particle::getScale() const
	{
		return scale;
	}

	sf::Vector2f particle::getPos() const
	{
		return pos;
	}

	float particle::getLifetime() const
	{
		return lifetime;
	}

	sf::Vector2f particle::getVelocity() const
	{
		return velocity;
	}

	void particle::setPos(sf::Vector2f toSet)
	{
		pos = toSet;
	}


	particleSystem::particleSystem(unsigned int particlesCount)
		: particle(getScale(),getPos(),getLifetime(),getVelocity())
	{}

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
			float ratio = elem.getLifetime() / getLifetime();
			// a is alpha
			vertices[i].color.a = static_cast<unsigned int>(ratio * 255);

		}
	}

	void particleSystem::resetParticle(size_t index)
	{
		// Give random velocity and lifetime to particle
		float angle = (std::rand() % 360);
	}

}