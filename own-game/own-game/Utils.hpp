#pragma once

#define UTILS
#ifdef UTILS

#include "pch.hpp"

namespace ownProject {
	class button
	{
	public:
		button(float paramScale, sf::Vector2f paramPos, std::string paramText);
		float getBtnScale();
		float getBtnScale() const;
		sf::Vector2f getBtnPos();
		sf::Vector2f getBtnPos() const;
		std::string getBtnText();
		std::string getBtnText() const;

		void setBtnPos(float paramPosX, float paramPosY);

	private:
		float btnScale;
		sf::Vector2f btnPos;
		std::string btnText;
	};

	class buttonPopUp : public button
	{
	public:
		buttonPopUp(float paramButtonMargin = 0.f);
		void addButton(float paramScale, float paramPosX, float paramPosY, std::string paramText);
		void AutoArrange(bool init);
		void fade(int type, float duration = 1.0f, float targetAlpha = 1.0f, bool scaleSize = true, bool up = true, float speed = 1.0f);
		void draw(sf::RenderWindow& paramWindow, sf::Sprite paramBtnSprite, sf::Text paramBtnText);

	private:
		float buttonMargin;
		std::vector<button> buttonArray;
	};

	// This is to set sprite origin to center
	sf::Vector2f setSpriteOrigin(sf::FloatRect tempRect);
	sf::Vector2f setTextOrigin(sf::FloatRect tempRect);
}

#endif // UTILS
