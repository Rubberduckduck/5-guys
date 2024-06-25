#pragma once

#ifndef SAND
#define SAND

#include "pch.hpp"
#include "state.hpp"
#include "GameLoop.hpp"
#include "ParticleSystem.hpp"

namespace ownProject {

	class sand : public state
	{
	public:
		sand(gameDataRef paramData);

		// State functions
		void Load();
		void Init();
		void HandleInput();
		void Update(float dt);
		void Draw(float dt);
		void Free();
		void Unload();

	private:
		gameDataRef data;
		sf::Mouse mouse;
	};
}


#endif // SAND