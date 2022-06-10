#include "Obstaculo.h"

Obstaculo::Obstaculo()
{
	
	_texture1.loadFromFile("Assets/Nivel/Pisos.png");
	_obst1.setTexture(_texture1);
	_obst1.setTextureRect({ 0,28,64,28 });
	/*_obst2.setTexture(_texture1);
	_obst2.setTextureRect({ 0,84,96,28 });
	_obst3.setTexture(_texture1);
	_obst3.setTextureRect({ 0,0,128,28 });
	_obst4.setTexture(_texture1);
	_obst4.setTextureRect({ 0,56,192,28 });
	_obst4.setPosition(200, 500);
	_obst3.setPosition(200, 300);
	_obst2.setPosition(200, 400);*/
	_obst1.setPosition(200, 500);
}

void Obstaculo::update()
{
}

void Obstaculo::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(_obst4, states);
}




sf::Sprite Obstaculo::getobst1() const
{
	return _obst1;
}

sf::Sprite Obstaculo::getobst2() const
{
	return _obst2;
}

sf::Sprite Obstaculo::getobst3() const
{
	return _obst3;
}

sf::Sprite Obstaculo::getobst4() const
{
	return _obst4;
}

void Obstaculo::setobst1()
{
	_obst1.setTexture(_texture1);
	_obst1.setTextureRect({ 0,28,64,28 });
	_obst1.setPosition(200, 500);
}

void Obstaculo::setobst2() 
{
	_obst1.setTexture(_texture1);
	_obst1.setTextureRect({ 0,84,96,28 });
	_obst1.setPosition(200, 400);
}

void Obstaculo::setobst3() 
{
	_obst1.setTexture(_texture1);
	_obst1.setTextureRect({ 0,0,128,28 });
	_obst1.setPosition(200, 300);
}

void Obstaculo::setobst4() 
{
	_obst1.setTexture(_texture1);
	_obst1.setTextureRect({ 0,56,192,28 });
	_obst1.setPosition(200, 600);
}

sf::FloatRect Obstaculo::getBounds() const
{
	return _obst4.getGlobalBounds();
}

sf::Vector2f Obstaculo::getposition1() const
{
	return _obst4.getPosition();
}


