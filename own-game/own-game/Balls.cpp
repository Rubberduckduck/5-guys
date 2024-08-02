#include "pch.hpp"
#include "Balls.hpp"

namespace ownProject {

	ballSystem::ballSystem(int setBallCount) : balls(setBallCount)
	{
	}

	void ballSystem::setBallRadius(float toSet)
	{
		for (sf::CircleShape& elem : balls)
		{
			elem.setRadius(toSet);
		}
	}

	void ballSystem::setBallSides(int toSet)
	{
		for (sf::CircleShape& elem : balls)
		{
			elem.setPointCount(toSet);
		}
	}


}