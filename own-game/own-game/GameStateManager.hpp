#pragma once

#include "pch.hpp"

#include "State.hpp"

#ifndef STATEMANAGER
#define STATEMANAGER

namespace ownProject {

	// Typedef for unique ptrs for state
	
	// Unque ptrs are ptrs is a smart pointer that owns and manages another object through 
	// a pointer and disposes of that object when the unique_ptr goes out of scope.

	typedef std::unique_ptr<state> stateRef;

	class stateManager
	{
	public:
		stateManager() {}
		
		void AddState(stateRef newState, bool isReplacing = false); // isReplacing boolean is used for replacing current state
		void RemoveState();

		void UpdateStates();

		void FreeStates();

		stateRef& GetActiveState();

	private:
		// std::stack a container adaptor that gives the programmer the functionality of a stack
		// LIFO: LAST-IN FIRST OUT TYPA MENTAILITY
		std::stack<stateRef> GameStates;
		stateRef state;
		bool isAdded = false;
		bool isRemoved = false;
		bool isReplaced = false;
	};

}

#endif // STATEMANAGER
