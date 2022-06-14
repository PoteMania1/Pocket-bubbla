#include "Obstaculo.h"

Obstaculo::Obstaculo()
{
	
	_texture1.loadFromFile("Assets/Nivel/Pisos.png");
	_obst1[0].setTexture(_texture1);
	_obst1[0].setTextureRect({0,28,64,28});
	_obst1[0].setPosition(200, 500);
}

void Obstaculo::update()
{
}

void Obstaculo::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(_obst1[0], states);
}

sf::Sprite Obstaculo::getobst1() const
{
	return _obst1[0];
}

void Obstaculo::setobst1()
{
	_obst1[0].setTexture(_texture1);
	//_obst1.setTextureRect({ 0,28,64,28 });
	_obst1[0].setPosition(200, 500);
}

sf::FloatRect Obstaculo::getBounds() const
{
	return _obst1[0].getGlobalBounds();
}

sf::Vector2f Obstaculo::getposition1() const
{
	return _obst1[0].getPosition();
}


