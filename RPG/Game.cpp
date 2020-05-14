#include "Game.h"

/**
Inicjalizacja okna oraz jego opcji z pliku.
*/
void Game::initWindow()
{
	ifstream ustawienia("cfg/window.ini");
	string tytul = "None"
		VideoMode window_bounds(800, 600);
	unsigned framerate_limit = 120;
	bool vertical_sync_enabled(false);
	if (ustawienia.is_open())
	{
		getline(ustawienia, tytul);
		ustawienia >> window_bounds.width >> window_bounds.height;
		ustawienia >> framerate_limit;
		ustawienia >> vertical_sync_enabled;
	}

	this->window = new RenderWindow(window_bounds, tytul);
	this->window->setFramerateLimit(framerate_limit);
	this->setVerticalSyncEnabled(vertical_sync_enabled);
}
/**
	Konstruktor i destruktor
*/
Game::Game()
{
	this->initWindow();
}

Game::~Game()
{
	delete this->window;
}

void Game::updateTime()
{
	this->time = timeClock.restart().asSeconds();

	system("cls");
	cout << time << "\n";
}

/**
	Ta funkcja odpowiada za renderowanie przedmiotów.
*/
void Game::render()
{
	this->window->clear();
	this->window->display();
}

void Game::update()
{
	this->updateEvents();
}

/**
	Uruchomienie okna.
*/
void Game::run()
{
	while (this->window->isOpen())
	{
		this->updateTime();
		this->update();
		this->render();
	}
}

void Game::updateEvents()
{

	while (this->window->pollEvent(event))
	{
		switch (event.type)
		{
		case Event::Closed:
			this->window->close();
			break;
		case Event::KeyPressed:
			if (event.key.code == Keyboard::Escape)
				this->window->close();
			break;
		}
	}
}
