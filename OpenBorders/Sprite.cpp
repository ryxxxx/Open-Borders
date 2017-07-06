#include "Sprite.h"

using namespace ob;

Sprite::Sprite()
{
	createWindow();
}


Sprite::Sprite(SpriteSheet& spriteSheet)
{
	createWindow();
	setSpriteSheet(spriteSheet);
}

Sprite::Sprite(const Sprite& other)
{
	spriteSheet = other.spriteSheet;
	currentFrame = other.currentFrame;
	position = other.position;
	active = other.active;
	window = other.window;
}


Sprite::~Sprite()
{
}


void Sprite::setSpriteSheet(SpriteSheet& spriteSheet)
{
	this->spriteSheet = std::shared_ptr<SpriteSheet>(&spriteSheet);
}


void Sprite::draw()
{
	//draw the current frame
	spriteSheet->draw((*window), currentFrame);
	//poll all events
	sf::Event e;
	while (window->pollEvent(e)) {}
}


void Sprite::setFrame(unsigned int frame)
{
	currentFrame = frame;
}


void Sprite::setPosition(sf::Vector2f position)
{
	this->position = position;
	window->setPosition(sf::Vector2i(static_cast<int>(position.x + 0.5f), static_cast<int>(position.y + 0.5f)));
}


void Sprite::setPosition(float x, float y)
{
	setPosition(sf::Vector2f(x, y));
}


sf::Vector2f Sprite::getPosition()
{
	return position;
}


void Sprite::setActive(bool active)
{
	this->active = active;
}


bool Sprite::isActive()
{
	return active;
}


#ifdef _WIN32
#include <Windows.h>

void Sprite::createWindow()
{
	window = std::make_shared<sf::RenderWindow>();
	window->create(sf::VideoMode(0, 0), "", sf::Style::None);
	window->setPosition(sf::Vector2i{ 0,0 });
	HWND handle = window->getSystemHandle();
	//hide window icon from taskbar
	DWORD win32Style = WS_VISIBLE;

	win32Style |= WS_EX_TOOLWINDOW;
	win32Style &= ~(WS_EX_APPWINDOW);
	
	ShowWindow(handle, SW_HIDE);
	SetWindowLongPtr(handle, GWL_EXSTYLE, win32Style);
	ShowWindow(handle, SW_SHOW);
}
#endif