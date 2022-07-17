#include "Nivel1.h"

Nivel1::Nivel1()
{
	_texture.loadFromFile("Assets/Niveles/1/Fondo.png");
	_fondo.setTexture(_texture);
	_texture1.loadFromFile("Assets/Niveles/1/0x45y.png");
	_obst1.setTexture(_texture1);
	_obst1.setPosition(0,45);
	_texture2.loadFromFile("Assets/Niveles/1/0x383y.png");
	_obst2.setTexture(_texture2);
	_obst2.setPosition(0,383);
	_texture3.loadFromFile("Assets/Niveles/1/0x472y.png");
	_obst3.setTexture(_texture3);
	_obst3.setPosition(0,472);//this
	_texture4.loadFromFile("Assets/Niveles/1/0x568y.png");
	_obst4.setTexture(_texture4);
	_obst4.setPosition(0,568);
	_texture5.loadFromFile("Assets/Niveles/1/32x109y.png");
	_obst5.setTexture(_texture5);
	_obst5.setPosition(32,109);
	_texture6.loadFromFile("Assets/Niveles/1/0x504y.png");
	_obst6.setTexture(_texture6);
	_obst6.setPosition(0, 504);//this
	_texture7.loadFromFile("Assets/Niveles/1/0x536y.png");
	_obst7.setTexture(_texture7);
	_obst7.setPosition(0, 536);//this
	_texture8.loadFromFile("Assets/Niveles/1/160x137y.png");
	_obst8.setTexture(_texture8);
	_obst8.setPosition(160, 137);
	_texture9.loadFromFile("Assets/Niveles/1/240x476y-416x415y-416x169y-640x472y-640x191y.png");
	_obst9.setTexture(_texture9);
	_obst9.setPosition(240, 476);
	_texture10.loadFromFile("Assets/Niveles/1/240x476y-416x415y-416x169y-640x472y-640x191y.png");
	_obst10.setTexture(_texture10);
	_obst10.setPosition(416, 415);
	_texture11.loadFromFile("Assets/Niveles/1/240x476y-416x415y-416x169y-640x472y-640x191y.png");
	_obst11.setTexture(_texture11);
	_obst11.setPosition(416, 169);
	_texture12.loadFromFile("Assets/Niveles/1/240x476y-416x415y-416x169y-640x472y-640x191y.png");
	_obst12.setTexture(_texture12);
	_obst12.setPosition(640, 472);
	_texture13.loadFromFile("Assets/Niveles/1/561x61y.png");
	_obst13.setTexture(_texture13);
	_obst13.setPosition(561, 61);
	_texture16.loadFromFile("Assets/Niveles/1/240x476y-416x415y-416x169y-640x472y-640x191y.png");
	_obst16.setTexture(_texture16);
	_obst16.setPosition(640, 191);
	_texture17.loadFromFile("Assets/Niveles/1/160x287y.png");
	_obst17.setTexture(_texture17);
	_obst17.setPosition(160, 287);
}

void Nivel1::update()
{
}

void Nivel1::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(_fondo, states);//1
	target.draw(_obst1, states);//2
	target.draw(_obst2, states);//3
	target.draw(_obst3, states);//4
	target.draw(_obst4, states);//5
	target.draw(_obst5, states);//6
	target.draw(_obst6, states);//7
	target.draw(_obst7, states);//8
	target.draw(_obst8, states);//9
	target.draw(_obst9, states);//10
	target.draw(_obst10, states);//11
	target.draw(_obst11, states);//12
	target.draw(_obst12, states);//13
	target.draw(_obst13, states);//14
	target.draw(_obst16, states);//17
	target.draw(_obst17, states);//18
}


sf::Sprite Nivel1::getfondo() const
{
	return _fondo;
}

sf::FloatRect Nivel1::getBounds() const
{
	return _fondo.getGlobalBounds();
}

sf::FloatRect Nivel1::getGlobalBounds1() const
{
	return _obst1.getGlobalBounds();
}

sf::FloatRect Nivel1::getGlobalBounds2() const
{
	return _obst2.getGlobalBounds();
}

sf::FloatRect Nivel1::getGlobalBounds3() const
{
	return _obst3.getGlobalBounds();
}

sf::FloatRect Nivel1::getGlobalBounds4() const
{
	return _obst4.getGlobalBounds();
}
	
sf::FloatRect Nivel1::getGlobalBounds5() const
{
	return _obst5.getGlobalBounds();
}

sf::FloatRect Nivel1::getGlobalBounds6() const
{
	return _obst6.getGlobalBounds();
}

sf::FloatRect Nivel1::getGlobalBounds7() const
{
	return _obst7.getGlobalBounds();
}

sf::FloatRect Nivel1::getGlobalBounds8() const
{
	return _obst8.getGlobalBounds();
}

sf::FloatRect Nivel1::getGlobalBounds9() const
{
	return _obst9.getGlobalBounds();
}

sf::FloatRect Nivel1::getGlobalBounds10() const
{
	return _obst10.getGlobalBounds();
}

sf::FloatRect Nivel1::getGlobalBounds11() const
{
	return _obst11.getGlobalBounds();
}

sf::FloatRect Nivel1::getGlobalBounds12() const
{
	return _obst12.getGlobalBounds();
}

sf::FloatRect Nivel1::getGlobalBounds13() const
{
	return _obst13.getGlobalBounds();
}

sf::FloatRect Nivel1::getGlobalBounds16() const
{
	return _obst16.getGlobalBounds();
}

sf::FloatRect Nivel1::getGlobalBounds17() const
{
	return _obst17.getGlobalBounds();
}

sf::Vector2f Nivel1::getposition1() const
{
	return _obst1.getPosition();
}

sf::Vector2f Nivel1::getposition2() const
{
	return _obst2.getPosition();
}

sf::Vector2f Nivel1::getposition3() const
{
	return _obst3.getPosition();
}

sf::Vector2f Nivel1::getposition4() const
{
	return _obst4.getPosition();
}

sf::Vector2f Nivel1::getposition5() const
{
	return _obst5.getPosition();
}

sf::Vector2f Nivel1::getposition6() const
{
	return _obst6.getPosition();
}

sf::Vector2f Nivel1::getposition7() const
{
	return _obst7.getPosition();
}

sf::Vector2f Nivel1::getposition8() const
{
	return _obst8.getPosition();
}

sf::Vector2f Nivel1::getposition9() const
{
	return _obst9.getPosition();
}

sf::Vector2f Nivel1::getposition10() const
{
	return _obst10.getPosition();
}

sf::Vector2f Nivel1::getposition11() const
{
	return _obst11.getPosition();
}

sf::Vector2f Nivel1::getposition12() const
{
	return _obst12.getPosition();
}

sf::Vector2f Nivel1::getposition13() const
{
	return _obst13.getPosition();
}

sf::Vector2f Nivel1::getposition16() const
{
	return _obst16.getPosition();
}

sf::Vector2f Nivel1::getposition17() const
{
	return _obst17.getPosition();
}
