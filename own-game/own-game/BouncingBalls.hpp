#pragma once

#ifndef BOUNCINGBALLS
#define BOUNCINGBALLS

#include "pch.hpp"
#include "state.hpp"
#include "GameLoop.hpp"

namespace ownProject {

	class bouncingBall : public state
	{
	public:
		bouncingBall(gameDataRef paramData);

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


#endif // bouncingBall