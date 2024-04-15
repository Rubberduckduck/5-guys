#include "pch.hpp"
#include "GameStateManager.hpp"

namespace gameState {

	void stateManager::AddState(stateRef newState, bool isReplacing)
	{
		this->isAdded = true;
		this->isReplaced = isReplacing;


		// Std::move transfer ownership of param newState to the game manager stack 
		this->state = std::move(newState);
	}
	void stateManager::RemoveState()
	{
		this->isRemoved = true;
		// Handle changes under updateStates
	}
	void stateManager::UpdateStates()
	{

		// Handling removing of state
		if (this->isRemoved && !this->GameStates.empty()) {
			// Remove state
			this->GameStates.pop();
			// Check if there are any states left
			if (!this->GameStates.empty())
			{
				this->GameStates.top()->Resume();
			}
			// Rmb set back to false after removing
			this->isReplaced = false;
		}

		// Hanlding of adding state
		if (this->isAdded)
		{
			if (!this->GameStates.empty())
			{
				// Replace current state
				if (this->isReplaced) {
					// Remove current state
					this->GameStates.pop();
				}
				// Dont do anyth
				else {
					this->GameStates.top()->Pause();
				}
			}
			// Add state to GameStates
			this->GameStates.push(std::move(this->state));
			// Call the init state
			this->GameStates.top()->Init();
			this->isAdded = false;
		}
	}
	stateRef& stateManager::GetActiveState()
	{
		return this->GameStates.top();
	}
}

