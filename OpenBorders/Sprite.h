#pragma once
#include <SFML\Graphics.hpp>
#include <memory>
#include "SpriteSheet.h"

namespace ob {
	class Sprite
	{
	public:
		Sprite();
		Sprite(SpriteSheet& spriteSheet);
		Sprite(const Sprite& other);
		~Sprite();

		void setSpriteSheet(SpriteSheet& spriteSheet);
		void setFrame(unsigned int frame);
		void setPosition(sf::Vector2f position);
		void setPosition(float x, float y);
		sf::Vector2f getPosition();
		void draw();
		void setActive(bool active);
		bool isActive();
	private:
		std::shared_ptr<SpriteSheet> spriteSheet;
		unsigned short currentFrame = 0;
		sf::Vector2f position;
		std::shared_ptr<sf::RenderWindow> window;
		bool active = true;

		void createWindow();
	};
};