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

		// Settors
		void setBallRadius(float toSet);
		void setBallSides(int toSet);

	private:
		std::vector<sf::CircleShape> balls;
	};
}

#endif 



