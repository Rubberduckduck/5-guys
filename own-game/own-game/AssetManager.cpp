#include "pch.hpp"
#include "AssetManager.hpp"

namespace ownProject {

	void assetManager::LoadTexture(std::string textName, std::string path)
	{
		// Create a local sf texture instance
		sf::Texture toAdd;
		if (toAdd.loadFromFile(path))
		{
			this->textureList[textName] = toAdd;
		}
	}

	sf::Texture& assetManager::GetTexture(std::string textName)
	{
		return this->textureList.at(textName);
	}

	void assetManager::LoadFont(std::string textName, std::string path)
	{
		// Create a local sf font instance
		sf::Font toAdd;
		if (toAdd.loadFromFile(path))
		{
			this->fontList[textName] = toAdd;
		}
	}

	sf::Font& assetManager::GetFont(std::string textName)
	{
		return this->fontList.at(textName);
	}
}


