#pragma once
#include "System.h"
#include "GraphicsComponent.h"

class GraphicsSystem : public ob::System<GraphicsComponent>
{
public:
	GraphicsSystem();
	virtual ~GraphicsSystem();
};

