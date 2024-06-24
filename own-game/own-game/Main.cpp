/*******************************************************************
*
* SOME NOTES TO TAKE NOTE: 
* 
* NAMING CONVENTIONS: 
* NORMAL VARIABLES, CLASSES, NAMESPACES: bryanLim
* DEFINES: BRYAN_LIM
* FUNCTION: BryanLim()
* 
* VARIABLE TYPES: 
* FOR FLOAT AND INT TYPES: USE BUILT-IN TYPES (e.g float, double)
* 
* ALL TO WORK UNDER NAMESPACE "ownProject" UNLESS STATED OTHERWISE
* 
* 
* ALL TEXTURES/AUDIOS ARE LOADED THROUGH THE STATE CLASSES BY ASSETMANAGER
* THROUGH GAMEDATAREF, IN ORDER TO RENDER, MAKE MEMBER FUNCTION DRAW THAT
* TAKES IN RENDER WINDOW AND WATEVER UW TO DRAW
* 
*******************************************************************/


#include "pch.hpp"
#include "GameLoop.hpp"
#include "Defines.hpp"

int main()
{
	// For memory leak checks
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	ownProject::gameLoop(WINDOW_HEIGHT, WINDOW_WIDTH, "BRY OWN SIMULATIONS");
	// TEMPORARY
	return EXIT_SUCCESS;
}