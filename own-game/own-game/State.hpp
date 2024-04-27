#pragma once

#ifndef STATE
#define STATE


/****************************************
* Initializing base state for inheritance 
****************************************/

namespace ownProject {

	class state
	{
	public:
		// State functions
		virtual void Init() = 0;
		virtual void HandleInput() = 0;
		virtual void Update(float dt) = 0;
		virtual void draw(float dt) = 0;

		// Pause and resume state
		virtual void Pause() {}
		virtual void Resume() {}

		// Clear warnings
		virtual ~state() {}
	};
}

#endif //STATE