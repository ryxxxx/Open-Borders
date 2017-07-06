#pragma once
#include <string>
#include <vector>
#include <memory>
#include <SFML\Graphics.hpp>
#include "Frame.h"

namespace ob
{
	class SpriteSheet
	{
	public:
		SpriteSheet();
		SpriteSheet(const std::string &filename);
		SpriteSheet(const SpriteSheet &copy);
		~SpriteSheet();

		void loadFromFile(const std::string& filename);
		void draw(sf::RenderWindow& window, unsigned int frame);
	private:
		std::shared_ptr<sf::Texture> texture;
		std::vector<std::shared_ptr<Frame>> frames;
	};
};