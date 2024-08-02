#pragma once
#include "pch.hpp"

#ifndef INPUTMANAGER
#define INPUTMANAGER

namespace ownProject {
	class inputManager
	{
	public:
		inputManager() {}
		~inputManager() {}

		// Some examples of input checking
		// PASSING IN WINDOW AS PARAM TO CHECK WHICH WINDOW EVENT IS AT
		bool IsSpriteClicked(sf::Sprite objInst, sf::Mouse::Button button, sf::RenderWindow& window); 

		// To get mouse position
		sf::Vector2i GetMousePosition(sf::RenderWindow& window);

	private:

				
	};
}

#endif // INPUTMANAGER
