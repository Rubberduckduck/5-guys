#include "pch.hpp"
#include "InputManager.hpp"

namespace ownProject {
	bool inputManager::IsSpriteClicked(sf::Sprite objInst, sf::Mouse::Button button, sf::RenderWindow& window)
	{
		// First detect button clicked
		if (sf::Mouse::isButtonPressed(button))
		{
			sf::IntRect playButton(static_cast<int> (objInst.getPosition().x), static_cast<int> (objInst.getPosition().y),
				static_cast<int> (objInst.getGlobalBounds().width), static_cast<int> (objInst.getGlobalBounds().height));

			// Check mouse position in button, check collision of mouse and button
			if (playButton.contains(sf::Mouse::getPosition(window)))
			{
				return true;
			}
		}
		return false;
	}

	sf::Vector2i inputManager::GetMousePosition(sf::RenderWindow& window)
	{
		return sf::Mouse::getPosition(window);
	}
}


