#include "pch.hpp"
#include "Utils.hpp"
#include "Defines.hpp"

namespace ownProject {
	button::button(float paramScale, sf::Vector2f paramPos, std::string paramText) 
		: btnScale{paramScale}, btnPos{paramPos}, btnText{paramText}
	{
	}

	float button::getBtnScale()
	{
		return btnScale;
	}

	float button::getBtnScale() const
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

	std::string button::getBtnText() const
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

	void buttonPopUp::draw(sf::RenderWindow& window, sf::Sprite& paramBtnSprite, sf::Text& paramBtnText)
	{

		window.clear();
		for (button const& elem : buttonArray)
		{

			paramBtnSprite.setPosition(elem.getBtnPos());
			paramBtnSprite.setScale(elem.getBtnScale(),elem.getBtnScale());
			// To draw button
			window.draw(paramBtnSprite);

			// To draw text
			paramBtnText.setString(elem.getBtnText());
			paramBtnText.setPosition(elem.getBtnPos().x - paramBtnSprite.getGlobalBounds().width / 3, elem.getBtnPos().y - paramBtnSprite.getGlobalBounds().height / 4);
			paramBtnText.setCharacterSize(TEXT_SCALE);
			paramBtnText.setFillColor(sf::Color::White);

			window.draw(paramBtnText);

			
		}
		window.display();
	}

	bool buttonPopUp::isButtonClicked(sf::Sprite& paramBtnSprite, sf::Mouse& paramMouseBtn, sf::RenderWindow& window)
	{
		for (button const& elem : buttonArray)
		{
			float MostTop = elem.getBtnPos().y - paramBtnSprite.getGlobalBounds().height / 2;
			float MostBot = elem.getBtnPos().y + paramBtnSprite.getGlobalBounds().height / 2;
			float MostLeft = elem.getBtnPos().x - paramBtnSprite.getGlobalBounds().width / 2;
			float MostRight = elem.getBtnPos().x + paramBtnSprite.getGlobalBounds().width / 2;

			// Get the current mouse position in the window
			sf::Vector2i mousePos = paramMouseBtn.getPosition(window);

			// Normalise mouse pos to world coordinates
			sf::Vector2f mouseNormPos = window.mapPixelToCoords(mousePos);

			float mouseX = mouseNormPos.x;
			float mouseY = mouseNormPos.y;

			// Checking coordinate 
			if (mouseX >= MostLeft && mouseX <= MostRight && mouseY >= MostTop && mouseY <= MostBot)
			{
				std::cout << "button clicked" << std::endl;
				return true;
			}
		}

		return false;
	}

	sf::Vector2f setSpriteOrigin(sf::FloatRect tempRect)
	{
		sf::Vector2f result;

		result.x = tempRect.left + tempRect.width / 2.0f;
		result.y = tempRect.top + tempRect.height / 2.0f;

		return result;
	}

	sf::Vector2f setTextOrigin(sf::FloatRect tempRect)
	{
		sf::Vector2f result;

		result.x = tempRect.left + tempRect.width / 2.0f;
		result.y = tempRect.top + tempRect.height / 2.0f;

		return result;
	}

}


