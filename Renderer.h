#include "SFML/Graphics.hpp"

class Renderer
{
	public:
		void drawCharAt(int x, int y, char _char);
		void init();
		//This is for compatibility
		void move(int x, int y);
		void addch(char _char);
	private:
		const int WIDTH = 132;
		const int HEIGHT = 43;
		sf::Font font;
		int curx;
		int cury;
};
