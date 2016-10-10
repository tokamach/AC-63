All: cputest

cputest:
	clang --std=c++11 CPU.cpp Panel.cpp TestRig.cpp -lncurses -I. -o PanelTest

game: 
	clang --std=c++11 -o Astro Main.cpp Astro.cpp CPU.cpp Panel.cpp -lncurses -I.

