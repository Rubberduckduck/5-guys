#pragma once

#ifndef GSLIST
#define GSLIST

enum gameStates {
	// Splash Screen Always First ( Init 0 )
	GS_SplashScreen,
	GS_MainMenu,
	GS_StartGame,
	GS_Tutorial,
	GS_Credit,
	GS_Settings,
	GS_Leaderboard,

	//Other Levels Inbetween Main Menu & Restart
	GS_Restart,
	GS_Exit,

};

#endif //GSLIST