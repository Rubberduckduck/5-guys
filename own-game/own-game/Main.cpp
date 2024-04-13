#include "pch.hpp"
#include "System.hpp"
#include "GameStateManager.hpp"

//Globals
float windowHeight, windowWidth;
float originX, originY;
float gsRunTime, deltaTime;
float totalFrame;
float fontSize;
sf::Font gameFont;
// Global Window Object
sf::RenderWindow window;
// Clock object
sf::Clock clockObj;


int main()
{
    // Initialize window
    SystemInit();

    //Game Font
    fontSize = 56;
    if (!gameFont.loadFromFile("Assets/Font/Kenney Future Narrow.ttf")) {

    }

    //Initializing Global Variables
    // Store result of window get size in this vector
    sf::Vector2f windowSize;
    windowSize = static_cast<sf::Vector2f> (window.getSize());
    windowHeight = windowSize.y;
    windowWidth = windowSize.x;
    originX = windowWidth / 2;
    originY = windowHeight / 2;

	// Game Loop
	while (current != GS_Exit)
	{

		// Figure a way to tell SFML frame start

		if (current == GS_Restart) {
			current = previous;
			next = previous;
		}
		else {
			GameStateUpdate();
			fpLoad();
		}

		gsRunTime = clockObj.restart().asSeconds();

		fpInit();
		while (current == next) {
			// check all the window's events that were triggered since the last iteration of the loop
			sf::Event event;

			while (window.pollEvent(event))
			{

				//Updating Global Variables
				windowSize = static_cast<sf::Vector2f> (window.getSize());
				windowHeight = windowSize.y;
				windowWidth = windowSize.x;

				originX = windowWidth / 2;
				originY = windowHeight / 2;

				deltaTime = clockObj.getElapsedTime().asSeconds();
				gsRunTime += deltaTime;

				if (event.type == sf::Event::Closed)
				{
					SystemExit();
				}
			}

			fpUpdate();

			// Clear window 
			window.clear();

			fpDraw();

			window.display();
		}

		fpFree();

		if (next != GS_Restart) {
			fpUnload();
		}

		previous = current;
		current = next;
	}

	SystemExit();

    return 0;
}