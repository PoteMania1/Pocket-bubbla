#include "Obstaculo.h"

Obstaculo::Obstaculo()
{
	
	_texture1.loadFromFile("Assets/Nivel/6B.png");
	_obst1.setTexture(_texture1);
	_texture2.loadFromFile("Assets/Nivel/4B.png");
	_obst2.setTexture(_texture2);
	_texture3.loadFromFile("Assets/Nivel/2B.png");
	_obst3.setTexture(_texture3);
	//_obst1.setTextureRect({0,28,64,28});
	//_obst1.setPosition(200, 500);
}

void Obstaculo::update()
{
}

void Obstaculo::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(_obst1, states);
}

sf::Sprite Obstaculo::getobst1() const
{
	return _obst1;
}

void Obstaculo::setobst1()
{
	_obst1.setTexture(_texture1);
	_obst1.setTextureRect({ 0,28,64,28 });
	_obst1.setPosition(200, 500);
}

sf::FloatRect Obstaculo::getBounds() const
{
	return _obst1.getGlobalBounds();
}

sf::Vector2f Obstaculo::getposition1() const
{
	return _obst1.getPosition();
}

sf::Sprite Obstaculo::getSprite1() const
{
	return _obst1;
}

void Obstaculo::CargarVecObst(sf::Sprite *v, int Fx)
{
	//for(int x=0;x<Fx;x++){
		//_obst1.setPosition(28,30);
	v[0] = _obst1;
	v[1] = _obst1;
	v[2] = _obst1;
	v[3] = _obst1;
	v[4] = _obst1;
	v[5] = _obst1;
	v[6] = _obst1;
	v[7] = _obst2;
	v[8] = _obst3;
	//}
}


