#pragma once

#ifndef FIREWORKS
#define FIREWORKS

#include "pch.hpp"
#include "state.hpp"
#include "GameLoop.hpp"

namespace ownProject {

	class fireworks : public state
	{
	public:
		fireworks(gameDataRef paramData);

		// State functions
		void Init();
		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		gameDataRef data;

	};
}


#endif // FIREWORKS
