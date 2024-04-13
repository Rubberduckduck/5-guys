#pragma once

#ifndef GSMANAGER
#define GSMANAGER

#include "GameStateList.hpp"

typedef void(*FP)(void);

extern gameStates current, next, previous;
extern FP fpLoad, fpInit, fpUpdate, fpDraw, fpFree, fpUnload;

void GameStateInit(gameStates startingState);
void GameStateUpdate(void);

#endif //GSMANAGER