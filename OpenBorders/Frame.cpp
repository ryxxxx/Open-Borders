#include "Frame.h"

using namespace ob;

#ifdef _WIN32
#include <iostream>
Frame::Frame(sf::Image &image, sf::IntRect textureRectangle)
{
	this->textureRectangle = textureRectangle;
	const sf::Uint8 *pixels = image.getPixelsPtr();
	//window region gets created
	windowRegion = CreateRectRgn(0, 0, textureRectangle.width, textureRectangle.height);
	//for every pixel you check wether its alpha value is 0 and if thats true you remove it from the window region
	for (int i = textureRectangle.top; i < textureRectangle.top + textureRectangle.height; i++)
	{
		for (int j = textureRectangle.left; j < textureRectangle.left + textureRectangle.width; j++)
		{
			if (pixels[(j + i*image.getSize().x) * 4 + 3] == 0)
			{
				HRGN hRegionPixel = CreateRectRgn(j - textureRectangle.left, i - textureRectangle.top, j + 1 - textureRectangle.left, i + 1 - textureRectangle.top);
				CombineRgn(windowRegion, windowRegion, hRegionPixel, RGN_XOR);
				DeleteObject(hRegionPixel);
			}
		}
	}
	//the actual picture gets created
	float frameWidth = static_cast<float>(textureRectangle.width);
	float frameHeight = static_cast<float>(textureRectangle.height);
	float frameLeft = static_cast<float>(textureRectangle.left);
	float frameTop = static_cast<float>(textureRectangle.top);
	vertices.resize(4);
	vertices.setPrimitiveType(sf::PrimitiveType::Quads);
	vertices[0].position = sf::Vector2f(0, 0);
	vertices[1].position = sf::Vector2f(frameWidth, 0);
	vertices[2].position = sf::Vector2f(frameWidth, frameHeight);
	vertices[3].position = sf::Vector2f(0, frameHeight);
	vertices[0].texCoords = sf::Vector2f(frameLeft, frameTop);
	vertices[1].texCoords = sf::Vector2f(frameLeft + frameWidth, frameTop);
	vertices[2].texCoords = sf::Vector2f(frameLeft + frameWidth, frameTop + frameHeight);
	vertices[3].texCoords = sf::Vector2f(frameLeft, frameTop + frameHeight);
}


Frame::~Frame()
{
	DeleteObject(windowRegion);
}


void Frame::draw(sf::RenderWindow &window, sf::Texture &texture)
{
	//make window ready for drawing
	window.clear();
	window.setSize(sf::Vector2u{ static_cast<unsigned int>(textureRectangle.width), static_cast<unsigned int>(textureRectangle.height) });
	window.setView(sf::View{ sf::FloatRect{ 0, 0, static_cast<float>(textureRectangle.width), static_cast<float>(textureRectangle.height) } });
	//create a copy of the current frames region
	HRGN tempRegion = CreateRectRgn(0, 0, 1, 1);
	CombineRgn(tempRegion, windowRegion, NULL, RGN_COPY);
	//set the window region to be the copy
	SetWindowRgn(window.getSystemHandle(), tempRegion, true);
	//delete the copy
	DeleteObject(tempRegion);
	//draw the actual picture
	window.draw(vertices, &texture);
	window.display();
}
#endif