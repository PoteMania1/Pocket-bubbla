#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

#define Max_main_menu 4
class MainMenu
{
private:
	int _MainMenuSelected;
	sf::Font _font;
	sf::Text _mainMenu[Max_main_menu];


public:
	MainMenu(float ancho, float alto);
	void draw(sf::RenderTarget& window);
	void MoveUp();
	void MoveDown();

	int MainMenuPressed();
	~MainMenu();
};

