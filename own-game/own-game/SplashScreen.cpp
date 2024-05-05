#include "pch.hpp"
#include "SplashScreen.hpp"
#include "Defines.hpp"

float splashOpacity;
float splashTimer;


namespace ownProject {

	SplashScreen::SplashScreen(gameDataRef paramData) : data(paramData) {}

	void SplashScreen::Init()
	{
		// To load texture and set texture to the sprite using std::string
		data->assetManager.LoadTexture("splashScreen texture", SPLASHSCREEN_TEXTURE);
		splashSprite.setTexture(this->data->assetManager.GetTexture("splashScreen texture"));

		// Center image
		sf::FloatRect tempRect = splashSprite.getLocalBounds();

		// To set image origin to center of sprite, SFML default is top left
		splashSprite.setOrigin(tempRect.left + tempRect.width / 2.0f,
			tempRect.top + tempRect.height / 2.0f);
		// Set sprite position to center of screen
		splashSprite.setPosition(this->data->window.getView().getCenter());
	}

	void SplashScreen::HandleInput()
	{
		sf::Event event;

		// SFML Style, to handle input using sf::event

		while (data->window.pollEvent(event))
		{
			// To  close window properly, without this if statement, window does not close properly
			if (sf::Event::Closed == event.type)
			{
				data->window.close();
			}
		}
	}

	void SplashScreen::Update(float dt)
	{
		static_cast<void>(dt);

		// For updating of splashscreen update time
		if (clock.getElapsedTime().asSeconds() > SPLASHSCREEN_TIME)
		{
			// For now, use print statement check
			std::cout << "MAIN MENU" << std::endl;
			splashTimer -= clock.getElapsedTime().asSeconds();
		}

		//// Convert opacity to 255 range
		//splashOpacity = 255 - (splashTimer * 255);

		//// Update opacity of splashscreen
		//splashSprite.setColor(sf::Color(0,0,0,splashOpacity));
	}

	void SplashScreen::draw(float dt)
	{
		static_cast<void>(dt);

		data->window.clear();
		data->window.draw(splashSprite);
		data->window.display();

	}
}

