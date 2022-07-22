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
	//Score
	_mainMenu[1].setFont(_font);
	_mainMenu[1].setFillColor(sf::Color::White);
	_mainMenu[1].setString("Score");
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

	//Score
	_textureScore.loadFromFile("Assets/Menu/Fondo.png");
	_score.setTexture(_textureScore);

}

void MainMenu::draw(sf::RenderTarget& window,bool status,bool score)
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

	if (score) {
		window.draw(_score);
		CargarScore();
		for (int x = 0; x < 10; x++) {
			window.draw(_Score[x]);
			//std::cout << hud[x].toString() << std::endl;
		}
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

void MainMenu::CargarScore()
{
	for (int x = 0; x < 10; x++) {
		/*if (Score[x].LeerDeDisco(x)) {
			_Score[x].setFont(_font);
			_Score[x].setFillColor(sf::Color::White);
			_Score[x].setString(Score[x].toString());
			_Score[x].setCharacterSize(15);
			//_hud[x].setOrigin(_hud[x].getGlobalBounds().width / 2,
				//_hud[x].getGlobalBounds().height / 2);
			_Score[x].setPosition(350, 20 * x);
		}*/
		if (Score.LeerDeDisco(x)) {
			if (Score.getPuntos() > puntos[0]) {
				puntos[0] = Score.getPuntos();
				break;
			}
			else if (Score.getPuntos() > puntos[1]) {
				puntos[1] = Score.getPuntos();
				break;
			}
			else if (Score.getPuntos() > puntos[2]) {
				puntos[2] = Score.getPuntos();
				break;
			}
			else if (Score.getPuntos() > puntos[3]) {
				puntos[3] = Score.getPuntos();
				break;
			}
			else if (Score.getPuntos() > puntos[4]) {
				puntos[4] = Score.getPuntos();
				break;
			}
			else if (Score.getPuntos() > puntos[5]) {
				puntos[5] = Score.getPuntos();
				break;
			}
			else if (Score.getPuntos() > puntos[6]) {
				puntos[6] = Score.getPuntos();
				break;
			}
			else if (Score.getPuntos() > puntos[7]) {
				puntos[7] = Score.getPuntos();
				break;
			}
			else if (Score.getPuntos() > puntos[8]) {
				puntos[8] = Score.getPuntos();
				break;
			}
			else if (Score.getPuntos() > puntos[9]) {
				puntos[9] = Score.getPuntos();
				break;
			}
		}
		_Score[x].setFont(_font);
		_Score[x].setFillColor(sf::Color::White);
		_Score[x].setString(std::to_string(puntos[x]));
		_Score[x].setCharacterSize(15);
		//_hud[x].setOrigin(_hud[x].getGlobalBounds().width / 2,
			//_hud[x].getGlobalBounds().height / 2);
		_Score[x].setPosition(350, 20 * x);
	}
}
