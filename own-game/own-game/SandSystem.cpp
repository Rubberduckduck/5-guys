#include "pch.hpp"
#include "SandSystem.hpp"


namespace ownProject {
	sandSystem::sandSystem()
	{
	}
	gridSystem::gridSystem() {

		sf::Vector2f startCord = { WINDOW_HEIGHT / 5, WINDOW_WIDTH / 5 };

		// Init grid 
		for (size_t i = 0; i < GRID_COLUMN_COUNT; ++i)
		{
			for (size_t j = 0; j < GRID_ROW_COUNT; ++j) {
				grid[i][j].cellPos = startCord;
			}
		}
	}
}

