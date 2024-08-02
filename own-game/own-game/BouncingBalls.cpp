#include "pch.hpp"
#include "BouncingBalls.hpp"
#include "MainMenu.hpp"

namespace ownProject {

	namespace {
		// To make single instance of system
		// std::unique_ptr<particleSystem> particleObj = std::make_unique<particleSystem>(1500);
	}

	bouncingBall::bouncingBall(gameDataRef paramData) : data{ paramData }
	{
	}

	void bouncingBall::Load()
	{
	}

	void bouncingBall::Init()
	{
	}

	void bouncingBall::HandleInput()
	{
	}

	void bouncingBall::Update(float dt)
	{
		// This is same as UNREFERENCED_PARAMETER
		static_cast<void>(dt);
	}

	void bouncingBall::Draw(float dt)
	{
		// This is same as UNREFERENCED_PARAMETER
		static_cast<void>(dt);
	}

	void bouncingBall::Free()
	{
	}

	void bouncingBall::Unload()
	{
	}



}