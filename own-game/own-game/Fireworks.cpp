#include "pch.hpp"
#include "Fireworks.hpp"
#include "MainMenu.hpp"

namespace ownProject {

	namespace {
		std::unique_ptr<particleSystem> particleObj = std::make_unique<particleSystem>(1500);
	}
	

	fireworks::fireworks(gameDataRef paramData) : data{paramData}
	{
	}

	void fireworks::Init()
	{
		std::cout << "fireworks state" << std::endl;
	}

	void fireworks::HandleInput()
	{
		sf::Event event;
		sf::Keyboard keyboard;

		// SFML Style, to handle input using sf::event

		while (data->window.pollEvent(event))
		{
			// To close window properly, without this if statement, window does not close properly
			if (sf::Event::Closed == event.type)
			{
				data->window.close();
			}
			if (keyboard.isKeyPressed(sf::Keyboard::Escape))
			{
				data->stateManager.AddState(stateRef(new mainMenu(data)), true);
			}
		}
	}

	void fireworks::Update(float dt)
	{
		// This is same as UNREFERENCED_PARAMETER
		static_cast<void>(dt);
		// Make particle follow mouse
		sf::Vector2i mousePos = mouse.getPosition(data->window);
		particleObj->setPos(data->window.mapPixelToCoords(mousePos));
		particleObj->update(dt);
	}

	void fireworks::Draw(float dt)
	{
		// This is same as UNREFERENCED_PARAMETER
		static_cast<void>(dt);
		std::cout << dt << std::endl;
		data->window.clear();
		data->window.draw(*particleObj);
		data->window.display();
	}


}