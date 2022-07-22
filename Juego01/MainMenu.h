#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Hud.h"
#include <iostream>

#define Max_main_menu 5
class MainMenu
{
private:
	int puntos[10]{};
	int _MainMenuSelected;
	sf::Font _font;
	sf::Text _mainMenu[Max_main_menu];
	sf::SoundBuffer _buffer;
	sf::Sound _sound;
	sf::Music music;
	sf::Texture _texture;
	sf::Texture _textureCred;
	sf::Texture _textureScore;
	sf::Sprite _fondo;
	sf::Sprite _creditos;
	sf::Sprite _score;
	Puntos Score;
	sf::Text _Score[10];

public:
	MainMenu(float ancho, float alto);
	void draw(sf::RenderTarget& window,bool status,bool score);
	void MoveUp();
	void MoveDown();
	void Sonidos();
	void SonidoFondo();
	void Stop();
	void CargarScore();

	int MainMenuPressed();
	~MainMenu();
};

