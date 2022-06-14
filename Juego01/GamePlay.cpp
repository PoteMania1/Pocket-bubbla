#include "GamePlay.h"
#include <iostream>


//void colisiones();

GamePlay::GamePlay()
{	
	x = 0;

	obst[10];

}

void GamePlay::cmd()
{
	
	p.cmd();
}

void GamePlay::update()
{
	p.update();
	it.update();
	if (p.isColision(it)) {
		it.respawn();
	}
	obst[0].setobst1();
	if (p.isColision(obst[0]) == true) {
		std::cout << "j";
		//posprev = obst.getposition1();
		//std::cout<<posprev.y<<"---" <<obst.getposition1().x << std::endl;
		p.respawn(obst[0].getPosition());
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
	int xs=0;
	target.draw(Ni.getfondo(), states);
	/*for (int x = 0; x < 4; x++;) {
		target.draw(obst[xs], states);
	}*/
	for (xs = 0; xs < 4; xs++) {
		xs++;
	}
	target.draw(p.getsprite(), states);
	target.draw(it.getsprite(), states);



}


