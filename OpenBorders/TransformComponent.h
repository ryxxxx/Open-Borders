#pragma once
#include <SFML\Graphics\Transform.hpp>
#include "Component.h"

class PositionComponent : public ob::Component<PositionComponent>
{
public:
	PositionComponent() {};
	virtual ~PositionComponent() {};

	void setPosition(float x, float y) { position.x = x; position.y = y; };
	void setPosition(sf::Vector2f position) { this->position = position; };
	void move(sf::Vector2f distance) { position += distance; };
	sf::Vector2f getPosition() { return position; };
private:
	sf::Vector2f position;
};

