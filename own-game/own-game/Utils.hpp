#pragma once

#define UTILS
#ifdef UTILS

#include "pch.hpp"
#include "GameLoop.hpp"

namespace ownProject {

	enum buttonID {
		TYPE_FIREWORKS = 0,
		TYPE_SAND,
		TYPE_WATER,
		TYPE_QUIT,
	};

	class button
	{
	public:
		button(float paramScale, sf::Vector2f paramPos, std::string paramText, buttonID paramButtonID, sf::Sprite paramSprite);
		button(float paramScale, float paramPosX, float paramPosY, std::string paramText, buttonID paramButtonID, sf::Sprite paramSprite);
		float getBtnScale();
		float getBtnScale() const;
		sf::Vector2f getBtnPos();
		sf::Vector2f getBtnPos() const;
		std::string getBtnText();
		std::string getBtnText() const;
		buttonID getBtnID();
		buttonID getBtnID() const;
		sf::Sprite& getBtnSprite();
		sf::Sprite getBtnSprite() const;
		void setBtnPos(float paramPosX, float paramPosY);

	private:
		float btnScale;
		sf::Vector2f btnPos;
		std::string btnText;
		buttonID btnID;
		sf::Sprite btnSprite;
	};

	class buttonPopUp : public button
	{
	public:
		buttonPopUp(float paramButtonMargin = 0.f);
		void addButton(float paramScale, float paramPosX, float paramPosY, std::string paramText, buttonID paramBtnID, sf::Sprite paramSprite);
		void AutoArrange(bool init);
		void fade(int type, float duration = 1.0f, float targetAlpha = 1.0f, bool scaleSize = true, bool up = true, float speed = 1.0f);
		void draw(sf::RenderWindow& paramWindow, sf::Text& paramBtnText);
		bool isButtonClicked(button& paramButton,sf::Mouse& paramMouseBtn, sf::RenderWindow& window);
		void buttonUpdate(sf::Mouse& paramMouseBtn, gameDataRef& paramData);
		void deleteButton();

	private:
		float buttonMargin;
		std::vector<button> buttonArray;
	};

	// This is to set sprite origin to center
	sf::Vector2f setSpriteOrigin(sf::FloatRect tempRect);
	sf::Vector2f setTextOrigin(sf::FloatRect tempRect);
}

#endif // UTILS
