test: main.cpp
	g++ main.cpp -o play -I include -L lib -l SDL2-2.0.0
ctest: main.c
	gcc main.c -o play -I include -L lib -l SDL2-2.0.0 -framework SDL2_ttf -F /Library/Frameworks
