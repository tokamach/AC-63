All: cputest
	#g++ -std=c++11 -o Astro Player.cpp Ship.cpp Renderer.cpp CPU.cpp Terminal.cpp -I. -lncurses

cputest:
	g++ -g -std=c++11 -o CpuTest CPU.cpp CPU.h Terminal.cpp Terminal.h TestRig.cpp -lncurses

cputestRender:
	g++ -std=c++11 -o CpuRender CPU.cpp CPU.h Terminal.cpp Terminal.h TestRenderRig.cpp Renderer.cpp Renderer.h -lncurses -lsfml-graphics -lsfml-window -lsfml-system
