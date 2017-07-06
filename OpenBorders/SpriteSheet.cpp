#include "SpriteSheet.h"
#include <pugixml.hpp>

using namespace ob;

SpriteSheet::SpriteSheet()
{
}


SpriteSheet::SpriteSheet(const std::string &filename)
{
	loadFromFile(filename);
}


SpriteSheet::SpriteSheet(const SpriteSheet &copy)
{
}


SpriteSheet::~SpriteSheet()
{
}


void SpriteSheet::loadFromFile(const std::string& filename)
{
	pugi::xml_document document;
	document.load_file(filename.c_str());
	pugi::xml_node xml_tilesheet = document.child("tilesheet");
	texture = std::make_shared<sf::Texture>();
	texture->loadFromFile(xml_tilesheet.attribute("source").as_string());
	sf::Image image;
	image.loadFromFile(xml_tilesheet.attribute("source").as_string());
	for (auto& i : xml_tilesheet.children("tile"))
	{
		sf::IntRect textureRectangle
		{ 
			i.attribute("left").as_int(),
			i.attribute("top").as_int(),
			i.attribute("width").as_int(),
			i.attribute("height").as_int()
		};
		frames.push_back(std::make_shared<Frame>(image, textureRectangle));
	}
}


void ob::SpriteSheet::draw(sf::RenderWindow& window, unsigned int frame)
{
	if (texture != nullptr)
		frames[frame]->draw(window, *texture);
}