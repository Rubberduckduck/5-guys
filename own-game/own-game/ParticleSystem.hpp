#pragma once

#define PARTICLESYSTEM
#ifdef PARTICLESYSTEM

#include "Defines.hpp"

namespace ownProject {

	// What properties of one particle have? (Entity)
	class particle
	{
	public:
		particle();
		particle(sf::Vector2i setScale, sf::Vector2f setPos, float setLifetime, sf::Vector2f setVelocity);
		// Getters that return a reference
		sf::Vector2i& getScale();
		sf::Vector2f& getPos();
		float& getLifetime();
		sf::Vector2f& getVelocity();
		// Getters that return const value
		sf::Vector2i getScale() const;
		sf::Vector2f getPos() const;
		float getLifetime() const;
		sf::Vector2f getVelocity() const;
		void setPos(sf::Vector2f toSet);


	private:
		sf::Vector2i scale;
		sf::Vector2f pos;
		float lifetime;
		sf::Vector2f velocity;
	};

	class particleSystem : public particle
	{
	public:
		particleSystem(unsigned int particlesCount);
		void update(float dt);
		void resetParticle(size_t index);




	private:
		sf::VertexArray vertices; // Vertex arrays contain vertices, which are the points to the vertex array shape	
		std::vector<particle> particles;
	};
}

#endif