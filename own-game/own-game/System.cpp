#include "pch.hpp"
#include "System.hpp"

extern sf::RenderWindow window;

void SystemInit() {

	// Set window size and window title
	window.create(sf::VideoMode(1600, 900), "Monkee Shootout");
	
	// Set FPS limit
	window.setFramerateLimit(60);

	// V-sync enabalation
	window.setVerticalSyncEnabled(false);
}

void SystemExit() {
	window.close();
}