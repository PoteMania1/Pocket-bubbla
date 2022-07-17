#include "GamePlay.h"
#include <iostream>


//void colisiones();

GamePlay::GamePlay():
	_ash(*this)
{
	/*for (int i = 0; i<10; i++) {
		_fruta.CargarVector(&_frutas[i].getsprite(), 10);
	}*/
	music.openFromFile("Sounds/Castlevania-SOTN-Draculas-Castle.wav");
	music.setVolume(15);
	_bufferMonedas.loadFromFile("Sounds/Ash/Agarrar-item.wav");
	_bufferMuerte.loadFromFile("Sounds/Ash/Muere.wav");
	_bufferAtaque.loadFromFile("Sounds/Ash/Ataque.wav");
	_colision = false;
	//_plataforma.CargarVecObst(_plataformaD, 25);
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
	_enemy2.cmd(_enemy2.getposition());
	if (music.getStatus() != sf::SoundSource::Status::Playing) {
		music.setVolume(15);
		music.play();
	}
	//movimientoPlataforma(_plataformaD[7], _preposPlataform);
	//movimientoPlataforma(_plataformaD[2], _preposPlataform2);
	_colision = false;
	_ash.update();
	_fruta.update();
	_enemy.update();
	_enemy2.update();
	_hud.Update();
	_hud.setPuntos(_puntos.getPuntos());
	//_puntos.Update();
	
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
		}
		else {
			bool iscolission = false;
			for (Ataque a: _haduken) {
				if (a.isColision(_enemy)) {
					i = _haduken.erase(i);
					_puntos.sumPuntos(200);
					_enemy.respawn();
					iscolission = true;
					break;
				}
				else if (a.isColision(_enemy2)) {
					i = _haduken.erase(i);
					_enemy2.respawn();
					_puntos.sumPuntos(200);
					iscolission = true;
					break;
				}
			}
			if (!iscolission) {
				i++;
			}
		}
	}

	/*if (_ash.isColision(_enemy)) {
		std::cout << "chocaste" << std::endl;
		_ash.controladorVida();
		_ash.setPosition(300, 600);
		_sound.setBuffer(_bufferMuerte);
		sonidos();
	}*/

	if (_ash.isColision(_fruta)) {
		_fruta.respawn();
		_puntos.sumPuntos(50);
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

	ColisionObst();
}

void GamePlay::movimientoPlataforma(sf::Sprite &plataforma,sf::Vector2f &prepos)
{
	sf::Vector2f const velocity = { 0,1 };
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
		_sound.setBuffer(_bufferAtaque);
		sonidos();
	}
	else {
		_haduken.push_back(Ataque(positionX, positionY,izqOder));
		_sound.setBuffer(_bufferAtaque);
		sonidos();
	}
}

void GamePlay::sonidos()
{
	if (_sound.getStatus() != sf::SoundSource::Status::Playing) {
		_sound.play();
	}

	else {
		_sound.stop();
	}
}

void GamePlay::ColisionObst()
{
	if (_ash.getPreviousPos().y < _ash.getposition().y
		&&_ash.getposition().y < 58
		&& _ash.getGlobalBounds().intersects(_nivel1.getGlobalBounds1())
		) {
			_ash.respawn(_nivel1.getposition1());
			_colision = true;
	}
	if (_ash.getPreviousPos().y < _ash.getposition().y
		&& _ash.getposition().y > 48
		&& _ash.getGlobalBounds().intersects(_nivel1.getGlobalBounds1())
		) {
		_ash.respawn(_nivel1.getposition5());
		_ash.setEstado(QUIETO);

		_colision = true;
	}
	else if (_ash.getPreviousPos().y < _ash.getposition().y
		&& _ash.getGlobalBounds().top + _ash.getGlobalBounds().height - _nivel1.getGlobalBounds2().top < 22
		&& _ash.getGlobalBounds().intersects(_nivel1.getGlobalBounds2())
		) {
			_ash.respawn(_nivel1.getposition2());
			_colision = true;
	}
	else if (_ash.getPreviousPos().y < _ash.getposition().y
		&& _ash.getGlobalBounds().intersects(_nivel1.getGlobalBounds3())
		) {
			_ash.respawn(_nivel1.getposition3());
			_colision = true;
	}
	else if (_ash.getPreviousPos().y < _ash.getposition().y
		&& _ash.getGlobalBounds().top + _ash.getGlobalBounds().height - _nivel1.getGlobalBounds4().top < 22
		&& _ash.getGlobalBounds().intersects(_nivel1.getGlobalBounds4())
		) {
			_ash.respawn(_nivel1.getposition4());
			_colision = true;
	}
	else if (_ash.getPreviousPos().y < _ash.getposition().y
		&& _ash.getGlobalBounds().top + _ash.getGlobalBounds().height - _nivel1.getGlobalBounds5().top < 22
		&& _ash.getGlobalBounds().intersects(_nivel1.getGlobalBounds5())
		) {
			_ash.respawn(_nivel1.getposition5());
			_colision = true;
	}
	else if (_ash.getPreviousPos().y < _ash.getposition().y
		&& _ash.getGlobalBounds().intersects(_nivel1.getGlobalBounds6())
		) {
			_ash.respawn(_nivel1.getposition6());
			_colision = true;
	}
	else if (_ash.getPreviousPos().y < _ash.getposition().y
		&& _ash.getGlobalBounds().intersects(_nivel1.getGlobalBounds7())
		) {
			_ash.respawn(_nivel1.getposition7());
			_colision = true;
	}
	else if (_ash.getPreviousPos().y < _ash.getposition().y
		&& _ash.getGlobalBounds().top + _ash.getGlobalBounds().height - _nivel1.getGlobalBounds8().top < 22
		&& _ash.getGlobalBounds().intersects(_nivel1.getGlobalBounds8())
		) {
			_ash.respawn(_nivel1.getposition8());
			_colision = true;
	}
	else if (_ash.getPreviousPos().y < _ash.getposition().y
		&& _ash.getGlobalBounds().top + _ash.getGlobalBounds().height - _nivel1.getGlobalBounds9().top < 22
		&& _ash.getGlobalBounds().intersects(_nivel1.getGlobalBounds9())
		) {
			_ash.respawn(_nivel1.getposition9());
			_colision = true;
	}
	else if (_ash.getPreviousPos().y < _ash.getposition().y
		&& _ash.getGlobalBounds().top + _ash.getGlobalBounds().height - _nivel1.getGlobalBounds10().top < 22
		&& _ash.getGlobalBounds().intersects(_nivel1.getGlobalBounds10())
		) {
			_ash.respawn(_nivel1.getposition10());
			_colision = true;
	}
	else if (_ash.getPreviousPos().y < _ash.getposition().y
		&& _ash.getGlobalBounds().top + _ash.getGlobalBounds().height - _nivel1.getGlobalBounds11().top < 22
		&& _ash.getGlobalBounds().intersects(_nivel1.getGlobalBounds11())
		&& _ash.getposition().x>479
		) {
			_ash.respawn(_nivel1.getposition11());
			_colision = true;
	}
	else if (_ash.getPreviousPos().y < _ash.getposition().y
		&& _ash.getGlobalBounds().top + _ash.getGlobalBounds().height - _nivel1.getGlobalBounds12().top < 22
		&& _ash.getGlobalBounds().intersects(_nivel1.getGlobalBounds12())
		) {
			_ash.respawn(_nivel1.getposition12());
			_colision = true;
	}
	else if (_ash.getPreviousPos().y < _ash.getposition().y
		&& _ash.getGlobalBounds().top + _ash.getGlobalBounds().height - _nivel1.getGlobalBounds13().top < 22
		&& _ash.getGlobalBounds().intersects(_nivel1.getGlobalBounds13())
		) {
			_ash.respawn(_nivel1.getposition13());
			_colision = true;
	}
	else if (_ash.getPreviousPos().y < _ash.getposition().y
		&& _ash.getGlobalBounds().top + _ash.getGlobalBounds().height - _nivel1.getGlobalBounds16().top < 22
		&& _ash.getGlobalBounds().intersects(_nivel1.getGlobalBounds16())
		) {
			_ash.respawn(_nivel1.getposition16());
			_colision = true;
	}
	else if (_ash.getPreviousPos().y < _ash.getposition().y
		&& _ash.getGlobalBounds().top + _ash.getGlobalBounds().height - _nivel1.getGlobalBounds17().top < 22
		&& _ash.getGlobalBounds().intersects(_nivel1.getGlobalBounds17())
		) {
			_ash.respawn(_nivel1.getposition17());
			_colision = true;
	}

	//setear estado caida
	if (_colision == false
		&& _ash.getGlobalBounds().top + _ash.getGlobalBounds().height < 590
		&& _ash.getEstado() != SALTANDO
		&& _ash.getEstado() != SALTODER
		&& _ash.getEstado() != SALTOIZQ) {

		_ash.setEstado(CAYENDO);
	}
	//costados de plataformas
	if (_ash.getGlobalBounds().left < 159 && _ash.getposition().y < 140 && _ash.getposition().x > 158 && _ash.getposition().y > 130) {
		_ash.respawn(_ash.getposition()- sf::Vector2f(0,32));
	}
	if (_ash.getGlobalBounds().left < 479 && _ash.getposition().y < 172 && _ash.getposition().x > 482 && _ash.getposition().y > 143) {
		_ash.respawn(_ash.getposition() - sf::Vector2f(0, 32));
	}
	if (_ash.getGlobalBounds().left < 100 && _ash.getposition().y < 573 && _ash.getposition().x > 95 && _ash.getposition().y > 539) {
		_ash.respawn(_ash.getposition() - sf::Vector2f(0, 32));
	}
}


void GamePlay::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	int xs = 0;
	target.draw(_nivel1, states);
	for (const Ataque& a : _haduken) {
 		target.draw(a, states);
	}
	target.draw(_ash.getsprite(), states);
	/*for (Item fruta : _frutas) {
		target.draw(fruta, states);
	}*/
	target.draw(_fruta.getsprite(), states);
	target.draw(_enemy.getsprite(), states);
	target.draw(_hud, states);
	target.draw(_enemy2.getsprite(), states);

	/*for (Enemigo wargreymon : _enemy) {		///MUCHOS WARGREYMONES
		target.draw(wargreymon.getsprite(), states);
	}*/
}


