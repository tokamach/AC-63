all: panel

panel:
	clang++ --std=c++14 CPU.cpp Panel.cpp TestRig.cpp -lncurses -I. -o PanelTest

test: 
	clang++ --std=c++14 CPU.cpp Test.cpp -I. -o tests
	./tests
	rm tests

clean:
	rm PanelTest
	rm tests
