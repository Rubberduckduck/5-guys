#include "pch.hpp"
#include "splashScreen.hpp"
#include "MainMenu.hpp"
#include "Defines.hpp"
#include "Utils.hpp"

unsigned int splashOpacity;
float splashTimer{};


namespace ownProject {

	splashScreen::splashScreen(gameDataRef paramData) : data(paramData) {}

	void splashScreen::Load()
	{
		//std::cout << "Load" << std::endl;

	}

	void splashScreen::Init()
	{
		//std::cout << "init" << std::endl;

		// To load texture and set texture to the sprite using std::string
		data->assetManager.LoadTexture("splashScreen texture", SPLASHSCREEN_TEXTURE);
		splashSprite.setTexture(this->data->assetManager.GetTexture("splashScreen texture"));

		// Load font 
		data->assetManager.LoadFont("UI font", FONT);

		// To set image origin to center of sprite, SFML default is top left
		splashSprite.setOrigin(setSpriteOrigin(splashSprite.getGlobalBounds()));
		// Set sprite position to center of screen
		splashSprite.setPosition(this->data->window.getView().getCenter());
	}

	void splashScreen::HandleInput()
	{
		sf::Event event;

		// SFML Style, to handle input using sf::event

		while (data->window.pollEvent(event))
		{
			// To close window properly, without this if statement, window does not close properly
			if (sf::Event::Closed == event.type)
			{
				data->window.close();
			}
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				data->stateManager.AddState(stateRef(new mainMenu(this->data)),true);
			}
		}
	}

	void splashScreen::Update(float dt)
	{
		static_cast<void>(dt);

		// For updating of splashscreen update time
		if (splashTimer <= SPLASHSCREEN_TIME)
		{
			// += to fade out
			// -= to fade in
			splashTimer += clock.restart().asSeconds();
		}
		else {
			data->stateManager.AddState(stateRef(new mainMenu(this->data)),true);
		}

		// Purpose of this: 
		// fractionElapsed represents the fraction of time that has elapsed relative to the total splash screen time (SPLASHSCREEN_TIME). 
		float fractionElapsed = 1.0f - (splashTimer / SPLASHSCREEN_TIME);

		// Convert fraction to opacity in the range of 0-255
		// SF::Uint8 is unsigned int, as we need opacity to be in 0-255 range, no negative
		// Once we have fractionElapsed, we multiply it by 255 to map it to the range of 0 to 255, which corresponds to the range of opacity values. 
		splashOpacity = static_cast<unsigned int>(fractionElapsed * 255);

		// Update opacity of splashscreen
		splashSprite.setColor(sf::Color(255, 255, 255, static_cast<sf::Uint8>(splashOpacity)));
	}

	void splashScreen::Draw(float dt)
	{

		static_cast<void>(dt);

		data->window.clear();
		data->window.draw(splashSprite);
		data->window.display();

	}

	void splashScreen::Free()
	{
	}

	void splashScreen::Unload()
	{
	}
}

