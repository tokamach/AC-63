#include "Renderer.h"
#include "SFML/Graphics.hpp"

void Renderer::init()
{
	font.loadFromFile("FreeSans.ttf"); 
}

void Renderer::drawCharAt(int x, int y, char _char)
{
	sf::Text text(_char, font);
	text.setCharacterSize(12);
	text.setStyle(sf::Text::Regular);
	window->draw(text);
}

void Renderer::move(int x, int y)
{
	curx = x;
	cury = y;
}

void Renderer::addch(char _char)
{
	drawCharAt(curx, cury, _char);
}
