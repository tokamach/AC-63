#include "Terminal.h"
#include "Renderer.h"
#include <iostream>
#include "SFML/Graphics.hpp"

int main()
{
	Terminal terminal;
	sf::RenderWindow * window = new sf::RenderWindow(sf::VideoMode(800, 600), "Astro CPU Test");
	Renderer rend;
	rend.init();
	terminal.init();

	while(window->isOpen())
	{
		sf::Event event;
		while(window->pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
			{
				window->close();
			}
		}

		window->clear();

		rend.drawCharAt(10, 10, '@');
		window->display();
	}
}
