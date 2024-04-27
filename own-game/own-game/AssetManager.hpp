#pragma once

#include "pch.hpp"

#define ASSETMANAGER
#ifdef ASSETMANAGER

// Temporary, for now we try use strings to tag assets
enum textureID
{
	TYPE_BULLET = 0,
	TYPE_PLAYER,
};

namespace ownProject {
	class assetManager
	{
	public:
		assetManager() {}
		~assetManager() {}
		
		// Load and get texture
		void LoadTexture(std::string textName, std::string path);
		sf::Texture& GetTexture(std::string textName);

		// Load and get font
		void LoadFont(std::string textName, std::string path);
		sf::Font& GetFont(std::string textName);

	private:
		// Containers to store textures and fonts
		std::map<std::string, sf::Texture> textureList;
		std::map<std::string, sf::Font> fontList;
	};
}

#endif // !ASSETMANAGER
