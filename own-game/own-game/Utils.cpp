#include "pch.hpp"
#include "Utils.hpp"
#include "Defines.hpp"
#include "Fireworks.hpp"
#include "Sand.hpp"

namespace ownProject {
	button::button(float paramScale, sf::Vector2f paramPos, std::string paramText, buttonID buttonID, sf::Sprite paramSprite)
		: btnScale{paramScale}, btnPos{paramPos}, btnText{paramText}, btnID{buttonID}, btnSprite{paramSprite}
	{
		btnSprite.setPosition(btnPos.x, btnPos.y);
		btnSprite.setScale(btnScale, btnScale);
	}

	button::button(float paramScale, float paramPosX, float paramPosY, std::string paramText, buttonID paramButtonID, sf::Sprite paramSprite)
		: btnScale{ paramScale }, btnText{ paramText }, btnID{ paramButtonID }, btnSprite{ paramSprite }
	{
		btnPos.x = paramPosX;
		btnPos.y = paramPosY;
		btnSprite.setPosition(btnPos.x, btnPos.y);
		btnSprite.setScale(btnScale,btnScale);
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

	buttonID button::getBtnID()
	{
		return btnID;
	}

	buttonID button::getBtnID() const
	{
		return btnID;
	}

	sf::Sprite& button::getBtnSprite()
	{
		return btnSprite;
	}

	sf::Sprite button::getBtnSprite() const
	{
		return btnSprite;
	}

	void button::setBtnPos(float paramPosX, float paramPosY)
	{
		btnPos.x = paramPosX;
		btnPos.y = paramPosY;
	}

	buttonPopUp::buttonPopUp(float paramButtonMargin)
		: button(getBtnScale(), getBtnPos(), getBtnText(), getBtnID(), getBtnSprite()), buttonMargin{paramButtonMargin}
	{
	}

	void buttonPopUp::addButton(float paramScale, float paramPosX, float paramPosY, std::string paramText, buttonID paramBtnID, sf::Sprite paramSprite)
	{
		// Set button pos
		setBtnPos(paramPosX,paramPosY);
		buttonArray.push_back(button(paramScale, getBtnPos(), paramText, paramBtnID, paramSprite));
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

	void buttonPopUp::draw(sf::RenderWindow& window, sf::Text& paramBtnText)
	{

		window.clear();
		for (button& elem : buttonArray)
		{
			// To draw button
			window.draw(elem.getBtnSprite());

			// To draw text
			paramBtnText.setString(elem.getBtnText());
			paramBtnText.setPosition(elem.getBtnPos().x - elem.getBtnSprite().getGlobalBounds().width / 3, elem.getBtnPos().y - elem.getBtnSprite().getGlobalBounds().height / 4);
			paramBtnText.setCharacterSize(TEXT_SCALE);
			paramBtnText.setFillColor(sf::Color::White);

			window.draw(paramBtnText);

			
		}
		window.display();
	}

	bool buttonPopUp::isButtonClicked(button& paramButton,sf::Mouse& paramMouseBtn, sf::RenderWindow& window)
	{
		float MostTop = paramButton.getBtnPos().y - paramButton.getBtnSprite().getGlobalBounds().height / 2;
		float MostBot = paramButton.getBtnPos().y + paramButton.getBtnSprite().getGlobalBounds().height / 2;
		float MostLeft = paramButton.getBtnPos().x - paramButton.getBtnSprite().getGlobalBounds().width / 2;
		float MostRight = paramButton.getBtnPos().x + paramButton.getBtnSprite().getGlobalBounds().width / 2;

		// Get the current mouse position in the window
		sf::Vector2i mousePos = paramMouseBtn.getPosition(window);

		// Normalise mouse pos to world coordinates
		sf::Vector2f mouseNormPos = window.mapPixelToCoords(mousePos);

		float mouseX = mouseNormPos.x;
		float mouseY = mouseNormPos.y;

		// Checking coordinate 
		if (mouseX >= MostLeft && mouseX <= MostRight && mouseY >= MostTop && mouseY <= MostBot)
		{
			return true;
		}

		return false;
	}

	void buttonPopUp::buttonUpdate(sf::Mouse& paramMouseBtn, gameDataRef& paramData)
	{

		bool buttonClicked = false;
		for (button& elem : buttonArray)
		{
			if (isButtonClicked(elem, paramMouseBtn, paramData->window) && paramMouseBtn.isButtonPressed(sf::Mouse::Left))
			{
				buttonClicked = true; 
				switch (elem.getBtnID())
				{
				case TYPE_FIREWORKS:
					deleteButton();
					next = GS_Fireworks;
					paramData->stateManager.AddState(stateRef(new fireworks(paramData)),true);
					break;

				case TYPE_SAND:
					deleteButton();
					next = GS_Sand;
					paramData->stateManager.AddState(stateRef(new sand(paramData)), true);
					break;

				case TYPE_BALL:
					deleteButton();
					std::cout << "water button clicked" << std::endl;
					break;

				case TYPE_QUIT:
					deleteButton();
					next = GS_Exit;
					paramData->window.close();
					break;

				default:
					break;
				}
				break;
			}
		}

		// This is to break out of for loop, once one button clicked no need continue iteration
		if (buttonClicked)
		{
			return;
		}
	}

	void buttonPopUp::deleteButton()
	{
		while (!buttonArray.empty())
		{
			buttonArray.pop_back();
		}
		
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


