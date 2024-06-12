#pragma once

#define PARTICLESYSTEM
#ifdef PARTICLESYSTEM

#include "Defines.hpp"

namespace ownProject {

	// What properties of one particle have? (Entity)
	// This class only contains the components (velocity, lifetime, pos)
	class particle
	{
	public:
		// Getters that return a reference
		float& getLifetime();
		sf::Vector2f& getVelocity();
		// Getters that return const value
		float getLifetime() const;
		sf::Vector2f getVelocity() const;
		//// Settors
		//void setLifetime(float toSet);
		//void setVelocity(sf::Vector2f toSet);


	private:
		float lifetime{};
		sf::Vector2f velocity;
	};

	// This class will contain functions that manipulate the particles
	class particleSystem : public particle, public sf::Transformable, public sf::Drawable
	{
	public:
		particleSystem(unsigned int particlesCount);
		void update(float dt);
		void resetParticle(size_t index);
		// Settor for particles
		void setPos(sf::Vector2f toSet);



	private:
		sf::VertexArray vertices; // Vertex arrays contain vertices, which are the points to the vertex array shape	
		std::vector<particle> particles;
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
		// Position whr particle will spawn
		sf::Vector2f pos;
		float particlesDuration;
	};
}

#endif