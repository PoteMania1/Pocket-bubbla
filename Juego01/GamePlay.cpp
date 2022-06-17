#include "GamePlay.h"
#include <iostream>


//void colisiones();

GamePlay::GamePlay()
{	
	x = 0;

	obst.CargarVecObst(obstFinal, 25);
	obstFinal[0].setPosition(48,365);
	obstFinal[1].setPosition(77,505);
	obstFinal[2].setPosition(305,472);
	obstFinal[3].setPosition(317,344);
	obstFinal[4].setPosition(520,413);
	obstFinal[5].setPosition(548,648);
	obstFinal[6].setPosition(552,252);
}

void GamePlay::cmd()
{
	
	p.cmd();
}

sf::Sprite GamePlay::getSprite1()
{
	return obstFinal[0];
}

void GamePlay::update()
{
	p.update();
	it.update();
	enemy.update();
	if (p.isColision(enemy)) {
		std::cout << "chocaste" << std::endl;
		p.pestaniaste();
		p.setPosition(300, 600);
	}
	if (p.isColision(it)) {
		it.respawn();
		p.sumandoando();
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
	for (sf::Sprite ob: obstFinal){
		if (p.getGlobalBounds().top + p.getGlobalBounds().height > ob.getGlobalBounds().top && p.getvelocidadSalto()<0 && p.getGlobalBounds().intersects(ob.getGlobalBounds())) {
			p.setPosition(p.getPosition().x, 590 + (p.getGlobalBounds().height - p.getOrigin().y));
			//ob.respawn(ob)
			p.respawn(ob.getPosition());
			//std::cout << "ella";
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
	int xs=0, xe=0;
	target.draw(Ni.getfondo(), states);
	/*for (int x = 0; x < 4; x++;) {
		target.draw(obst[xs], states);
	}*/
	for (xs = 0; xs < 7; xs++) {
		target.draw(obstFinal[xs], states);
	}
	target.draw(p.getsprite(), states);
	target.draw(it.getsprite(), states);
	target.draw(enemy.getsprite(), states);
	
	/*for (Enemigo wargreymon : enemy) {		///MUCHOS WARGREYMONES
		target.draw(wargreymon.getsprite(), states);
	}*/
}


