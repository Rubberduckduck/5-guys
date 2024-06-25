#include "pch.hpp"
#include "Sand.hpp"
#include "MainMenu.hpp"

namespace ownProject {


	sand::sand(gameDataRef paramData) : data{ paramData }
	{
	}

	void sand::Load()
	{
	}

	void sand::Init()
	{
		std::cout << "sand state" << std::endl;
	}

	void sand::HandleInput()
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
				next = GS_MainMenu;
				data->stateManager.AddState(stateRef(new mainMenu(data)), true);
			}
		}
	}

	void sand::Update(float dt)
	{
		// This is same as UNREFERENCED_PARAMETER
		static_cast<void>(dt);
	}

	void sand::Draw(float dt)
	{
		// This is same as UNREFERENCED_PARAMETER
		static_cast<void>(dt);

	}

	void sand::Free()
	{
	}

	void sand::Unload()
	{
	}
}