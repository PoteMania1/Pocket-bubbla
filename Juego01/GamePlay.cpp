#include "GamePlay.h"
#include <iostream>


//void colisiones();

GamePlay::GamePlay():
	_ash(*this)
{
	/*for (int i = 0; i<10; i++) {
		_fruta.CargarVector(&_frutas[i].getsprite(), 10);
	}*/
	music.openFromFile("Sounds/Soundtrack-1.wav");
	_bufferMonedas.loadFromFile("Sounds/Ash/Agarrar-item.wav");
	_bufferMuerte.loadFromFile("Sounds/Ash/Muere.wav");
	_bufferPasos.loadFromFile("Sounds/Ash/Pasos.wav");
	_colision = false;
	_plataforma.CargarVecObst(_plataformaD, 25);
	_plataformaD[0].setPosition(76, 505);
	_plataformaD[1].setPosition(304, 471);
	_plataformaD[2].setPosition(519, 413);
	_plataformaD[3].setPosition(200, 370);
	_plataformaD[4].setPosition(48, 265);
	_plataformaD[5].setPosition(128, 138);
	_plataformaD[6].setPosition(551, 152);
	_plataformaD[7].setPosition(336, 244);
	_plataformaD[8].setPosition(544, 283);
	_preposPlataform = _plataformaD[7].getPosition();
	_preposPlataform2 = _plataformaD[2].getPosition();
	auxMovPlataform = 0;
}

void GamePlay::cmd()
{
	_ash.cmd();
}

sf::Sprite GamePlay::getSprite1()
{
	return _plataformaD[0];
}

void GamePlay::update()
{
	if (music.getStatus() != sf::SoundSource::Status::Playing) {
		music.setVolume(15);
		music.play();
	}
	movimientoPlataforma(_plataformaD[7], _preposPlataform);
	movimientoPlataforma(_plataformaD[2], _preposPlataform2);
	_colision = false;
	_ash.update();
	_fruta.update();
	_enemy.update();
	_enemy2.update();
	
	/*for (Item& fruta : _frutas) {
		fruta.update();
		if(_ash.isColision(fruta)) {
			fruta.respawn();
			_ash.sumaPuntos();
			_sound.setBuffer(_bufferMonedas);
			sonidos();
		}
	}*/
	std::list<Ataque>::iterator i = _haduken.begin();

	while (i != _haduken.end()) {
		
		Ataque& a = (*i);
		a.update();
		
		if (a.getposition().x < 0|| a.getposition().x > 800) {
			i = _haduken.erase(i);
			std::cout << "borrado" << "\n";
		}
		else {
			bool iscolission = false;
			for (Ataque a: _haduken) {
				if (a.isColision(_enemy)) {
					i = _haduken.erase(i);
					_enemy.respawn();
					iscolission = true;
					break;
				}
				else if (a.isColision(_enemy2)) {
					i = _haduken.erase(i);
					_enemy2.respawn();
					iscolission = true;
					break;
				}
			}
			if (!iscolission) {
				i++;
			}
		}
	}

	if (_ash.isColision(_enemy)) {
		std::cout << "chocaste" << std::endl;
		_ash.controladorVida();
		_ash.setPosition(300, 600);
		_sound.setBuffer(_bufferMuerte);
		sonidos();
	}
	if (_ash.isColision(_fruta)) {
		_fruta.respawn();
		_ash.sumaPuntos();
		_sound.setBuffer(_bufferMonedas);
		sonidos();
	}
	/*for (Enemigo wargreymon : _enemy) { ///MUCHOS WARGREYMONES
		wargreymon.update();
	}*/
	/*for (Enemigo wargreymon : _enemy) {            ///MUCHOS WARGREYMONES
		if (_ash.isColision(wargreymon)) {
			std::cout << "chocaste" << std::endl;
			_ash.setPosition(300, 600);
		}
	}*/

	//setear posicion ash en plataformas
	for (sf::Sprite ob : _plataformaD) {
		if (_ash.getPreviousPos().y<_ash.getposition().y
			&& _ash.getGlobalBounds().intersects(ob.getGlobalBounds())
			&& _ash.getGlobalBounds().top + _ash.getGlobalBounds().height - ob.getGlobalBounds().top < 22
			){

			_ash.respawn(ob.getPosition());
			_colision = true;
		}

		//setear estado caida
		if (_colision == false
			&& _ash.getGlobalBounds().top + _ash.getGlobalBounds().height < 590
			&& _ash.getEstado() != SALTANDO
			&& _ash.getEstado() != SALTODER
			&& _ash.getEstado() != SALTOIZQ){

			_ash.setEstado(CAYENDO);
		}
		if (_ash.getGlobalBounds().top + _ash.getGlobalBounds().height > 590){

			_colision = true;
			_ash.setEstado(QUIETO);
		}
	}
}

void GamePlay::movimientoPlataforma(sf::Sprite &plataforma,sf::Vector2f &prepos)
{
	sf::Vector2f const velocity = { 0,1 };
	//std::cout << prepos.y <<"-----" << prepos.y - plataforma.getPosition().y <<"-----" << plataforma.getPosition().y << std::endl;
	if (prepos.y - plataforma.getPosition().y <80
		&& auxMovPlataform ==0) {
		plataforma.move(-velocity);
		if (prepos.y - plataforma.getPosition().y == 80) {
			auxMovPlataform++;
		}
	}
	if (prepos.y - plataforma.getPosition().y>0
		&& auxMovPlataform ==1) {
		plataforma.move(velocity);
		if (prepos.y - plataforma.getPosition().y == 0) {
			auxMovPlataform = 0;
		}
	}
}

void GamePlay::createBala(float positionX, float positionY,bool izqOder)
{
	if (izqOder) {
		_haduken.push_back(Ataque(positionX-50,positionY,izqOder));
	}
	else {
		_haduken.push_back(Ataque(positionX, positionY,izqOder));
	}
}

void GamePlay::sonidos()
{
	//_sound.setBuffer(buffer);
	if (_sound.getStatus() != sf::SoundSource::Status::Playing) {
			_sound.play();
			std::cout<<"sonando"<<"\n";
	}

	else {
		_sound.stop();
	}
}


void GamePlay::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	int xs = 0;
	target.draw(_nivel1.getfondo(), states);
	for (xs = 0; xs < 9; xs++) {
		target.draw(_plataformaD[xs], states);
	}
	for (const Ataque& a : _haduken) {
 		target.draw(a, states);
	}
	target.draw(_ash.getsprite(), states);
	/*for (Item fruta : _frutas) {
		target.draw(fruta, states);
	}*/
	target.draw(_fruta.getsprite(), states);
	target.draw(_enemy.getsprite(), states);
	target.draw(_enemy2.getsprite(), states);


	/*if (_estadoP == ESTADOS_PERSONAJE::ATAQUE) {
		target.draw(_hadoukenA[0], states);
	}*/
	/*for (Enemigo wargreymon : _enemy) {		///MUCHOS WARGREYMONES
		target.draw(wargreymon.getsprite(), states);
	}*/
}


