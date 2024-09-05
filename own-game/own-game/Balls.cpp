#include "pch.hpp"
#include "Balls.hpp"

namespace ownProject {

	ballSystem::ballSystem(int setBallCount) : balls(setBallCount)
	{
	}

	void ballSystem::InitializeBalls(float radiusToSet, int sidesToSet)
	{
		for (sf::CircleShape& elem : balls)
		{
			setBallRadius(radiusToSet);
			setBallSides(sidesToSet);
			elem.setOrigin(setBallOrigin(elem.getGlobalBounds()));
		}
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

	sf::Vector2f ballSystem::setBallOrigin(sf::FloatRect tempRect)
	{
		sf::Vector2f result;

		result.x = tempRect.left + tempRect.width / 2.0f;
		result.y = tempRect.top + tempRect.height / 2.0f;

		return result;

	}


}