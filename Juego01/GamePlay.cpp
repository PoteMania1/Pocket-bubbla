#include "GamePlay.h"
#include <iostream>


//void colisiones();

GamePlay::GamePlay():
	_ash(*this)
{
	_enemy3.setposition(sf::Vector2f(200, 381));
	_enemy4.setposition(sf::Vector2f(5, 381));
	music.openFromFile("Sounds/Castlevania-SOTN-Draculas-Castle.wav");
	music.setVolume(15);
	_bufferMonedas.loadFromFile("Sounds/Ash/Agarrar-item.wav");
	_bufferMuerte.loadFromFile("Sounds/Ash/Muere.wav");
	_bufferAtaque.loadFromFile("Sounds/Ash/Ataque.wav");
	_colision = false;
	auxMovPlataform = 0;
}

void GamePlay::cmd()
{
	_ash.cmd();
	_enemy2.cmd(_enemy2.getposition(),400);
	_enemy4.cmd(_enemy4.getposition(),50);
}

void GamePlay::update()
{
	if (music.getStatus() != sf::SoundSource::Status::Playing || music.getStatus() == sf::SoundSource::Status::Paused) {
		music.setVolume(15);
		music.play();
	}

	_colision = false;
	_ash.update();
	_enemy.update();
	_enemy3.update();
	_enemy2.update();
	_enemy4.update();
	_hud.Update();
	_hud.setPuntos(_puntos.getPuntos());
	_hud.setVidas(_vidas.getVidas());
	
	for (Item& fruta : _frutas) {
		fruta.update();
		if(_ash.isColision(fruta)) {
			fruta.respawn();
			_puntos.sumPuntos(50);
			_sound.setBuffer(_bufferMonedas);
			sonidos();
		}
	}


	ColisionObst();

	ColisionesAtaque(_enemy,_enemy2);
	ColisionesAtaque(_enemy3,_enemy4);

	ColisionesEnemigos(_enemy, _enemy2);
	ColisionesEnemigos(_enemy3, _enemy4);

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

void GamePlay::setVida()
{
	_ash.respawn(sf::Vector2f(300, 565));
	_vidas.setvida(4);
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

void GamePlay::setPuntos()
{
	_puntos.setPuntos(0);
}

void GamePlay::ColisionesAtaque(Enemigo& e, Enemigo2& e2)
{
	std::list<Ataque>::iterator i = _haduken.begin();

	while (i != _haduken.end()) {

		Ataque& a = (*i);
		a.update();

		if (a.getposition().x < 0 || a.getposition().x > 800) {
			i = _haduken.erase(i);
		}
		else if (a.isColision(e) && e.getEstadoVida()) {
			i = _haduken.erase(i);
			_puntos.sumPuntos(200);
			//e.setEstadoVida(false);
			e.respawn();
			//crearfrutas(_enemy.getposition());
			break;
		}
		else if (a.isColision(e2) && e2.getEstadoVida()) {
			i = _haduken.erase(i);
			_puntos.sumPuntos(200);
			//e2.setEstadoVida(false);
			e2.respawn();
			//crearfrutas(_enemy.getposition());
			break;
		}
		else {
			i++;
		}
	}
}

bool GamePlay::GameOver()
{
	if (_vidas.getVidas() == 0) {
		
		return true;
	}
	return false;
}

void GamePlay::ColisionesEnemigos(Enemigo& e, Enemigo2& e2)
{
	if (_ash.isColision(e) && e.getEstadoVida()) {
		_ash.setEstadoVida(false);
		_ash.setVidasMenos();
		_vidas.setVidasMenos();
		_sound.setBuffer(_bufferMuerte);
		sonidos();
	}

	if (_ash.isColision(e2) && e2.getEstadoVida()) {
		_ash.setEstadoVida(false);
		_ash.setVidasMenos();
		_vidas.setVidasMenos();
		_sound.setBuffer(_bufferMuerte);
		sonidos();
	}
}

int GamePlay::getvidas()
{
	return _vidas.getVidas();
}

int GamePlay::getpuntos()
{
	return _puntos.getPuntos();
}


/*void GamePlay::crearfrutas(sf::Vector2f pos)
{
	_frutas.push_back(Item(pos));
}*/

void GamePlay::draw(sf::RenderTarget& target, sf::RenderStates states) const {

	target.draw(_nivel1, states);

	for (const Ataque& a : _haduken) {
 		target.draw(a, states);
	}

	for (Item fruta : _frutas) {
		target.draw(fruta, states);
	}

	/*for (const Item& i : _frutas) {
		target.draw(i, states);
	}*/

	//target.draw(_fruta, states);
	target.draw(_enemy, states);
	target.draw(_enemy3, states);

	target.draw(_enemy2, states);
	target.draw(_enemy4, states);

	target.draw(_ash, states);

	target.draw(_hud, states);

	/*for (Enemigo wargreymon : _enemy) {		///MUCHOS WARGREYMONES
		target.draw(wargreymon.getsprite(), states);
	}*/
}


