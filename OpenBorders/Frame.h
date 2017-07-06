#pragma once
#include <SFML\Graphics.hpp>

#ifdef _WIN32
#include <Windows.h>

namespace ob {
	class Frame
	{
	public:
		Frame(sf::Image &image, sf::IntRect textureRectangle);
		~Frame();

		void draw(sf::RenderWindow &window, sf::Texture &texture);
	private:
		sf::IntRect textureRectangle;
		HRGN windowRegion;
		sf::VertexArray vertices;
	};
};

#endif