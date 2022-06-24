#include "GamePlay.h"
#include <iostream>


//void colisiones();

GamePlay::GamePlay()
{
	_estadoP = ESTADOS_PERSONAJE::QUIETO;
	x = 0;
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
	prepos = _plataformaD[7].getPosition();
}

void GamePlay::cmd()
{
	_hadouken.cmd();
	_ash.cmd();
}

sf::Sprite GamePlay::getSprite1()
{
	return _plataformaD[0];
}

void GamePlay::update()
{
	movimientoPlataforma(_plataformaD[7],prepos);
	_estadoP = _ash.getEstado();
	_colision = false;
	_hadouken.update();
	_ash.update();
	_fruta.update();
	_enemy.update();
	if (_ash.isColision(_enemy)) {
		std::cout << "chocaste" << std::endl;
		_ash.pestaniaste();
		_ash.setPosition(300, 600);
	}
	if (_ash.isColision(_fruta)) {
		_fruta.respawn();
		_ash.sumandoando();
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
	//obst.setobst1();
	/*for (int i = 0; i<7; i++) {
		if (p.isColision(obst) == true) {
			std::cout << "j";
			//posprev = obst.getposition1();
			//std::cout<<posprev.y<<"---" <<obst.getposition1().x << std::endl;
			p.respawn(obst.getposition1());
		}
	}*/
	for (sf::Sprite ob : _plataformaD) {
		if (_ash.getPreviousPos().y<_ash.getposition().y
			//&&_ash.getvelocidadSalto() < 0
			&& _ash.getGlobalBounds().intersects(ob.getGlobalBounds())
			&& _ash.getGlobalBounds().top + _ash.getGlobalBounds().height - ob.getGlobalBounds().top < 22
			)
		{
			//std::cout << _ash.getGlobalBounds().top + _ash.getGlobalBounds().height - ob.getGlobalBounds().top << std::endl;
			//std::cout <<_ash.getPreviousPos().y<<"------" << _ash.getposition().y << std::endl;
			_ash.respawn(ob.getPosition());
			//_ash.setEstado(QUIETO);
			_colision = true;
		}

		if (_colision == false
			&& _ash.getGlobalBounds().top + _ash.getGlobalBounds().height < 590
			//&& !_ash.getGlobalBounds().intersects(ob.getGlobalBounds())
			&& _ash.getEstado() != SALTANDO
			&& _ash.getEstado() != SALTODER
			&& _ash.getEstado() != SALTOIZQ) {
			std::cout <<"cayendo"<< std::endl;
			_ash.setEstado(CAYENDO);
		}
		if (_ash.getGlobalBounds().top + _ash.getGlobalBounds().height > 590) {
			_colision = true;
			_ash.setEstado(QUIETO);
		}
	}
}

void GamePlay::setx(int _x)
{
	x += _x;
}

int GamePlay::getx()
{
	return x;
}

void GamePlay::movimientoPlataforma(sf::Sprite &plataforma,sf::Vector2f &prepos)
{
	/*sf::Vector2f prepos = {0,0};
	if(a==0){
		prepos = plataforma.getPosition();
		std::cout << prepos.y << std::endl;
		a++;
	}*/
	sf::Vector2f const velocity = { 0,1 };
	std::cout << prepos.y <<"-----" << prepos.y - plataforma.getPosition().y <<"-----" << plataforma.getPosition().y << std::endl;
	if (prepos.y - plataforma.getPosition().y <=20) {
		plataforma.move(-velocity);
	}
	else {
		plataforma.move(velocity);
	}
}

void GamePlay::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	int xs = 0;
	target.draw(_nivel1.getfondo(), states);
	for (xs = 0; xs < 9; xs++) {
		target.draw(_plataformaD[xs], states);
	}
	target.draw(_ash.getsprite(), states);
	target.draw(_fruta.getsprite(), states);
	target.draw(_enemy.getsprite(), states);
	if (_estadoP == ESTADOS_PERSONAJE::ATAQUE) {
		target.draw(_hadouken.getsprite(), states);
	}



	/*for (Enemigo wargreymon : _enemy) {		///MUCHOS WARGREYMONES
		target.draw(wargreymon.getsprite(), states);
	}*/
}


