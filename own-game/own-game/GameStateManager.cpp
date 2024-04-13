#include "pch.hpp"
#include "GameStateManager.hpp"
#include "MainMenu.hpp"

/*************************************************************************************/
// EXTERN
/*************************************************************************************/
gameStates current = GS_MainMenu, next = GS_MainMenu, previous = GS_MainMenu;
FP fpLoad = nullptr, fpInit = nullptr, fpUpdate = nullptr, fpDraw = nullptr, fpFree = nullptr, fpUnload = nullptr;

/*************************************************************************************/
// GAMESTATES
/*************************************************************************************/
void GameStateInit(gameStates startingState) {
	previous = current = next = startingState;
}

void GameStateUpdate() {

	switch (current) {
	case GS_MainMenu:
		fpLoad = MainMenuLoad;
		fpInit = MainMenuInit;
		fpUpdate = MainMenuUpdate;
		fpDraw = MainMenuDraw;
		fpFree = MainMenuFree;
		fpUnload = MainMenuUnload;
		break;
	default:
		break;
	}

}