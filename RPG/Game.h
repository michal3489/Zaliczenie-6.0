#ifndef Game_H
#define Game_H

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <fstream>
#include <sstream>

using namespace sf;
using namespace std;

class Game
{
private:

	//Utworzenie obiektów klasy
	RenderWindow* window;
	Event event;
	Clock timeClock;

	float time;

	//inicjalizacja okna
	void initWindow();

public:

	// Konstruktor i destruktor
	Game();
	virtual ~Game();

	//Funkcje
	void updateTime();
	void render();
	void update();
	void run();
	void updateEvents();

};

#endif // !Game_H