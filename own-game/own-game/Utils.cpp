#include "pch.hpp"
#include "Utils.hpp"

namespace ownProject {
	button::button(float paramScale, sf::Vector2f paramPos, std::string paramText) 
		: btnScale{paramScale}, btnPos{paramPos}, btnText{paramText}
	{
	}

	float button::getBtnScale()
	{
		return btnScale;
	}

	sf::Vector2f button::getBtnPos()
	{
		return btnPos;
	}

	sf::Vector2f button::getBtnPos() const
	{
		return btnPos;
	}

	std::string button::getBtnText()
	{
		return btnText;
	}

	void button::setBtnPos(float paramPosX, float paramPosY)
	{
		btnPos.x = paramPosX;
		btnPos.y = paramPosY;
	}

	buttonPopUp::buttonPopUp(float paramButtonMargin)
		: button(getBtnScale(), getBtnPos(), getBtnText()), buttonMargin{paramButtonMargin}
	{
	}

	void buttonPopUp::addButton(float paramScale, float paramPosX, float paramPosY, std::string paramText)
	{
		// Set button pos
		setBtnPos(paramPosX, paramPosY); 
		buttonArray.push_back(button(paramScale, getBtnPos(), paramText));
		std::cout << getBtnPos().y << std::endl;
	}

	void buttonPopUp::AutoArrange(bool init)
	{  
		static_cast<void> (init);
		// MAYB OTTHER DAYS HEHE
	}

	void buttonPopUp::fade(int type, float duration, float targetAlpha, bool scaleSize, bool up, float speed)
	{
		static_cast<void> (type);
		static_cast<void> (duration);
		static_cast<void> (targetAlpha);
		static_cast<void> (scaleSize);
		static_cast<void> (up);
		static_cast<void> (speed);
		// MAYB OTTHER DAYS HEHE
	}

	void buttonPopUp::draw(sf::RenderWindow& window, sf::Sprite paramBtnSprite)
	{
		window.clear();
		for (button const& elem : buttonArray)
		{

			paramBtnSprite.setPosition(elem.getBtnPos());
			// To draw button
			window.draw(paramBtnSprite);

			
		}
		window.display();
	}

	sf::Vector2f setSpriteOrigin(sf::FloatRect tempRect)
	{
		sf::Vector2f result;

		result.x = tempRect.left + tempRect.width / 2.0f;
		result.y = tempRect.top + tempRect.height / 2.0f;

		return result;
	}

}


