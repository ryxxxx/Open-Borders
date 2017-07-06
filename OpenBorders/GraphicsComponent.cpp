#include "GraphicsComponent.h"


GraphicsComponent::GraphicsComponent()
{
}


GraphicsComponent::~GraphicsComponent()
{
}


void GraphicsComponent::loadFromFile(std::string file)
{
	spriteSheet.loadFromFile(file);
	sprite.setSpriteSheet(spriteSheet);
}


std::shared_ptr<ob::Sprite> GraphicsComponent::getSprite()
{
	return std::shared_ptr<ob::Sprite>(&sprite);
}