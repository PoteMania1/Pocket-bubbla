#include "GamePlay.h"
#include <iostream>


//void colisiones();

GamePlay::GamePlay(int nivel)
{
	_Plataforma = new Plataforma;
	x = 0;
	_Plataforma[0].getDraw(0).setPosition(500, 430);
	_Plataforma[1].getDraw(1).setPosition(400, 330);
	_Plataforma[2].getDraw(2).setPosition(300, 230);
	_Plataforma[3].getDraw(3).setPosition(200, 500);
	

}

GamePlay::GamePlay()
{	
	cantPlataformas = 4;
	vplataforma = new Plataforma[cantPlataformas];
	//Pisito[0].getDraw().setPosition(500, 500);
	//Pisito[1].getDraw().setPosition(400, 330);
	//Pisito[2].getDraw().setPosition(300, 230);
	//Pisito[3].getDraw().setPosition(200, 200);
	
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
	obst.setobst1();
	if (p.isColision(obst) == true) {
		std::cout << "j";
		//posprev = obst.getposition1();
		//std::cout<<posprev.y<<"---" <<obst.getposition1().x << std::endl;
		p.respawn(obst.getposition1());

	}
	//for (Plataforma ob : Pisito) {

	//	if (p.getGlobalBounds().top + p.getGlobalBounds().height <= ob.getDraw().getGlobalBounds().top && p.getvelocidadSalto() < 0) {
	//		std::cout << ob.getDraw().getGlobalBounds().top<<std::endl;
			//p.setPosition(1, 1);//p.getPosition().x,ob.getDraw().getGlobalBounds().top-20);
	//		p.quieto(p.getposition().x, ob.getDraw().getGlobalBounds().top - p.getPosition().y - 20);
	//	}
	//}
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
		target.draw(_Plataforma[xs], states);
	}*/
	for (xs = 0; xs < 4; xs++) {
		xs++;
	}
	_Plataforma[0].getDraw(0);
	_Plataforma[1].getDraw(1);
	_Plataforma[2].getDraw(2);
	_Plataforma[3].getDraw(3);
	//target.draw(obst.getobst4(), states);
	//target.draw(obst.getobst2(), states);
	//target.draw(obst.getobst3(), states);
	//target.draw(obst.getobst4(), states);
	
	target.draw(p.getsprite(), states);
	target.draw(it.getsprite(), states);



}


