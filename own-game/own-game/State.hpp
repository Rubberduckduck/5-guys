#pragma once

#ifndef STATE
#define STATE


/****************************************
* Initializing base state for inheritance 
****************************************/

namespace gameState {

	class state
	{
	public:
		// State functions
		virtual void Init() = 0;
		virtual void HandleInput() = 0;
		virtual void Update() = 0;
		virtual void draw(float dt) = 0;

		// Pause and resume ste
		virtual void Pause() {}
		virtual void Resume() {}

		// Clear warnings
		virtual ~state() {}
	};
}

#endif //STATE