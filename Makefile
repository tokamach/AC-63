All: cputest

cputest:
	g++ -g -std=c++11 -o PanelTest CPU.cpp CPU.h Panel.cpp Panel.h TestRig.cpp -lncurses -I.

game: 
	g++ -g -std=c++11 -o Astro Main.cpp Astro.cpp CPU.cpp -I. -lncurses
