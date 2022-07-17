#include "MainMenu.h"

MainMenu::MainMenu(float ancho, float alto)
{
	if (!_font.loadFromFile("Font/Perfect DOS VGA 437.ttf")) {
		std::cout << "No cargo la fuente.";
	}

	//PocketBubbla
	_mainMenu[4].setFont(_font);
	_mainMenu[4].setFillColor(sf::Color::White);
	_mainMenu[4].setString("Pocket Bubbla");
	_mainMenu[4].setCharacterSize(60);
	_mainMenu[4].setOrigin(_mainMenu[3].getGlobalBounds().width / 2,
		_mainMenu[4].getGlobalBounds().height / 2);
	_mainMenu[4].setPosition(180, 20);

	//Play
	_mainMenu[0].setFont(_font);
	_mainMenu[0].setFillColor(sf::Color::White);
	_mainMenu[0].setString("Play");
	_mainMenu[0].setCharacterSize(30);
	_mainMenu[0].setOrigin(_mainMenu[0].getGlobalBounds().width / 2,
		_mainMenu[0].getGlobalBounds().height / 2);
	_mainMenu[0].setPosition(710, 200);
	//Options
	_mainMenu[1].setFont(_font);
	_mainMenu[1].setFillColor(sf::Color::White);
	_mainMenu[1].setString("Options");
	_mainMenu[1].setCharacterSize(30);
	_mainMenu[1].setOrigin(_mainMenu[1].getGlobalBounds().width / 2,
		_mainMenu[1].getGlobalBounds().height / 2);
	_mainMenu[1].setPosition(710, 300);
	//About
	_mainMenu[2].setFont(_font);
	_mainMenu[2].setFillColor(sf::Color::White);
	_mainMenu[2].setString("About");
	_mainMenu[2].setCharacterSize(30);
	_mainMenu[2].setOrigin(_mainMenu[2].getGlobalBounds().width / 2,
		_mainMenu[2].getGlobalBounds().height / 2);
	_mainMenu[2].setPosition(710, 400);
	//Exit
	_mainMenu[3].setFont(_font);
	_mainMenu[3].setFillColor(sf::Color::White);
	_mainMenu[3].setString("Exit");
	_mainMenu[3].setCharacterSize(30);
	_mainMenu[3].setOrigin(_mainMenu[3].getGlobalBounds().width / 2,
		_mainMenu[3].getGlobalBounds().height / 2);
	_mainMenu[3].setPosition(710, 500);

	_MainMenuSelected = -1;
	//Sonido Menu
	_buffer.loadFromFile("Sounds/Menu/03 - MenuSelect.wav");
	_sound.setBuffer(_buffer);
	//Musica de Menu
	if (!music.openFromFile("Sounds/Menu/Castlevania-SOTN-Admiration-of-Clan.wav")) {
		std::cout << "No cargo la musica.";
	}
	//Fondo Menu
	_texture.loadFromFile("Assets/Menu/Fondo.png");
	_fondo.setTexture(_texture);
	//Creditos
	_textureCred.loadFromFile("Assets/Menu/Creditos.png");
	_creditos.setTexture(_textureCred);
}

void MainMenu::draw(sf::RenderTarget& window,bool status)
{
	//if(!status){
		//window.clear();
	window.draw(_fondo);
	for (int i = 0; i < Max_main_menu; i++) {
		window.draw(_mainMenu[i]);
	}
	SonidoFondo();
	
	if (status) {
		window.draw(_creditos);
	}
}

void MainMenu::MoveUp()
{
	if (_MainMenuSelected - 1 >= 0) {
		_mainMenu[_MainMenuSelected].setFillColor(sf::Color::White);

		_MainMenuSelected--;
		if (_MainMenuSelected < 0) {
			_MainMenuSelected = 3;
		}
		_mainMenu[_MainMenuSelected].setFillColor(sf::Color::Blue);
		Sonidos();
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
		Sonidos();
	}
}

int MainMenu::MainMenuPressed()
{
	return _MainMenuSelected;
}

void MainMenu::Sonidos()
{
	_sound.play();
}

MainMenu::~MainMenu()
{
}

void MainMenu::SonidoFondo()
{
	if (music.getStatus() != sf::SoundSource::Status::Playing) {
		music.setVolume(15);
		music.play();
	}
}

void MainMenu::Stop()
{
	music.stop();
}
