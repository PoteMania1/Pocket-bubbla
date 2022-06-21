#include "GamePlay.h"
#include <iostream>


//void colisiones();

GamePlay::GamePlay()
{
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
	/*for (Enemigo wargreymon : enemy) { ///MUCHOS WARGREYMONES
		wargreymon.update();
	}*/
	/*for (Enemigo wargreymon : enemy) {            ///MUCHOS WARGREYMONES
		if (p.isColision(wargreymon)) {
			std::cout << "chocaste" << std::endl;
			p.setPosition(300, 600);
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
			&& _ash.getEstado()!= SALTANDO
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

void GamePlay::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	int xs = 0, xe = 0;
	target.draw(_nivel1.getfondo(), states);
	/*for (int x = 0; x < 4; x++;) {
		target.draw(obst[xs], states);
	}*/
	for (xs = 0; xs < 9; xs++) {
		target.draw(_plataformaD[xs], states);
	}
	target.draw(_ash.getsprite(), states);
	target.draw(_fruta.getsprite(), states);
	target.draw(_enemy.getsprite(), states);
	if (ACTIVO==true) {
		target.draw(_hadouken.getsprite(), states);
	}

	/*for (Enemigo wargreymon : enemy) {		///MUCHOS WARGREYMONES
		target.draw(wargreymon.getsprite(), states);
	}*/
}


