#pragma once
#define SANDSYSTEM
#ifdef SANDSYSTEM

#include "ParticleSystem.hpp"


namespace ownProject {
	class sandSystem : public particle
	{
	public:
		sandSystem();

	private:

	};

	struct cell
	{
		float cellSize;
		sf::Vector2f cellPos;
		bool cellState;
		sf::Vector2f normCellPos;
	};

	// Class grid has many cells and functions to manipulate the cells
	class gridSystem
	{
	public:
		gridSystem();

	private:

		// 2D array indexed will be column major first, then row
		std::array<std::array<cell, GRID_COLUMN_COUNT>, GRID_ROW_COUNT> grid;
	};

}

#endif 
