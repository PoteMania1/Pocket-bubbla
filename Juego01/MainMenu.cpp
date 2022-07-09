#include "MainMenu.h"

MainMenu::MainMenu(float ancho, float alto)
{
	if (!_font.loadFromFile("Font/Perfect DOS VGA 437.ttf")) {
		std::cout << "No cargo la fuente.";
	}

	//Play
	_mainMenu[0].setFont(_font);
	_mainMenu[0].setFillColor(sf::Color::White);
	_mainMenu[0].setString("Play");
	_mainMenu[0].setCharacterSize(30);
	_mainMenu[0].setOrigin(_mainMenu[0].getGlobalBounds().width / 2,
		_mainMenu[0].getGlobalBounds().height / 2);
	_mainMenu[0].setPosition(400, 200);
	//Options
	_mainMenu[1].setFont(_font);
	_mainMenu[1].setFillColor(sf::Color::White);
	_mainMenu[1].setString("Options");
	_mainMenu[1].setCharacterSize(30);
	_mainMenu[1].setOrigin(_mainMenu[1].getGlobalBounds().width / 2,
		_mainMenu[1].getGlobalBounds().height / 2);
	_mainMenu[1].setPosition(400, 300);
	//About
	_mainMenu[2].setFont(_font);
	_mainMenu[2].setFillColor(sf::Color::White);
	_mainMenu[2].setString("About");
	_mainMenu[2].setCharacterSize(30);
	_mainMenu[2].setOrigin(_mainMenu[2].getGlobalBounds().width / 2,
		_mainMenu[2].getGlobalBounds().height / 2);
	_mainMenu[2].setPosition(400, 400);
	//Exit
	_mainMenu[3].setFont(_font);
	_mainMenu[3].setFillColor(sf::Color::White);
	_mainMenu[3].setString("Exit");
	_mainMenu[3].setCharacterSize(30);
	_mainMenu[3].setOrigin(_mainMenu[3].getGlobalBounds().width / 2,
		_mainMenu[3].getGlobalBounds().height / 2);
	_mainMenu[3].setPosition(400, 500);

	_MainMenuSelected = -1;
}

void MainMenu::draw(sf::RenderTarget& window)
{
	for (int i = 0; i < Max_main_menu; i++) {
		window.draw(_mainMenu[i]);
	}
}

void MainMenu::MoveUp()
{
	if (_MainMenuSelected - 1 >= 0) {
		_mainMenu[_MainMenuSelected].setFillColor(sf::Color::White);

		_MainMenuSelected--;
		if (_MainMenuSelected == -1) {
			_MainMenuSelected = 2;
		}
		_mainMenu[_MainMenuSelected].setFillColor(sf::Color::Blue);
	}
}

void MainMenu::MoveDown()
{
	if (_MainMenuSelected + 1 <= Max_main_menu) {
		_mainMenu[_MainMenuSelected].setFillColor(sf::Color::White);

		_MainMenuSelected++;
		if (_MainMenuSelected == 4) {
			_MainMenuSelected = 0;
		}
		_mainMenu[_MainMenuSelected].setFillColor(sf::Color::Blue);
	}
}

int MainMenu::MainMenuPressed()
{
	return _MainMenuSelected;
}

MainMenu::~MainMenu()
{
}
