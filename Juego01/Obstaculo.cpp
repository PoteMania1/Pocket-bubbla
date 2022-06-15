#include "Obstaculo.h"

Obstaculo::Obstaculo()
{
	
	_texture1.loadFromFile("Assets/Nivel/Capa 22 copia.png");
	_obst1.setTexture(_texture1);
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
	for(int x=0;x<Fx;x++){
		//_obst1.setPosition(28,30);
		v[x] = _obst1;
	}
}


