#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

#define Max_main_menu 5
class MainMenu
{
private:
	int _MainMenuSelected;
	sf::Font _font;
	sf::Text _mainMenu[Max_main_menu];
	sf::SoundBuffer _buffer;
	sf::Sound _sound;
	sf::Music music;
	sf::Texture _texture;
	sf::Texture _textureCred;
	sf::Sprite _fondo;
	sf::Sprite _creditos;


public:
	MainMenu(float ancho, float alto);
	void draw(sf::RenderTarget& window,bool status);
	void MoveUp();
	void MoveDown();
	void Sonidos();
	void SonidoFondo();
	void Stop();

	int MainMenuPressed();
	~MainMenu();
};

