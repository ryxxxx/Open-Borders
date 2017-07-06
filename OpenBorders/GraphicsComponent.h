#pragma once
#include "Component.h"
#include "Sprite.h"

class GraphicsComponent : public ob::Component<GraphicsComponent>
{
public:
	GraphicsComponent();
	virtual ~GraphicsComponent();

	void loadFromFile(std::string file);
	std::shared_ptr<ob::Sprite> getSprite();
private:
	ob::Sprite sprite;
	ob::SpriteSheet spriteSheet;
};

