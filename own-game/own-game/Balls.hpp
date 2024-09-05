#pragma once

#ifndef BALLSYSTEM
#define BALLSYSTEM


namespace ownProject {
	class ballSystem
	{
	public:
		// sf::CircleShape has two attibutes: radius and number of sides (optional) 
		// Number of sides is for quality of circles to be rendered 
		ballSystem(int setBallCount);

		// Initialize balls
		void InitializeBalls(float radiusToSet, int sidesToSet);

		// Settors
		void setBallRadius(float toSet);
		void setBallSides(int toSet);

		// Set Origin 
		sf::Vector2f setBallOrigin(sf::FloatRect tempRect);

	private:
		std::vector<sf::CircleShape> balls;
	};
}

#endif 



