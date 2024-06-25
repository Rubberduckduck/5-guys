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
		virtual void Load() = 0;
		virtual void Init() = 0;
		virtual void HandleInput() = 0;
		virtual void Update(float dt) = 0;
		virtual void Draw(float dt) = 0;
		virtual void Free() = 0;
		virtual void Unload() = 0;

		// Pause and resume state
		virtual void Pause() {}
		virtual void Resume() {}

		// Clear warnings
		virtual ~state() {}
	};

	enum gameStateType {

		GS_SplashScreen = 0,
		GS_MainMenu,
		GS_Fireworks,
		GS_Sand,

		// Restart and Exit is last 2 enums! Do not CHANGE
		GS_Restart,
		GS_Exit,
	};
}

#endif //STATE