#pragma once

#ifndef FIREWORKS
#define FIREWORKS

#include "pch.hpp"
#include "state.hpp"
#include "GameLoop.hpp"
#include "ParticleSystem.hpp"

namespace ownProject {

	class fireworks : public state
	{
	public:
		fireworks(gameDataRef paramData);

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


#endif // FIREWORKS
