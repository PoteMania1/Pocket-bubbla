#pragma once
#include <SFML/Graphics.hpp>
#include "Colisionable.h"

class Nivel1 : public sf::Drawable, public colisionable, public sf::Transformable
{
private:
	sf::Sprite _fondo;
	sf::Texture _texture;
	sf::Texture _texture1;
	sf::Texture _texture2;
	sf::Texture _texture3;
	sf::Texture _texture4;
	sf::Texture _texture5;
	sf::Texture _texture6;
	sf::Texture _texture7;
	sf::Texture _texture8;
	sf::Texture _texture9;
	sf::Texture _texture10;
	sf::Texture _texture11;
	sf::Texture _texture12;
	sf::Texture _texture13;
	sf::Texture _texture16;
	sf::Texture _texture17;
	sf::Sprite _obst1;
	sf::Sprite _obst2;
	sf::Sprite _obst3;
	sf::Sprite _obst4;
	sf::Sprite _obst5;
	sf::Sprite _obst6;
	sf::Sprite _obst7;
	sf::Sprite _obst8;
	sf::Sprite _obst9;
	sf::Sprite _obst10;
	sf::Sprite _obst11;
	sf::Sprite _obst12;
	sf::Sprite _obst13;
	sf::Sprite _obst16;
	sf::Sprite _obst17;

	int _frame = 0;
public:
	//static int spri;
	Nivel1();
	void update();
	void draw(sf::RenderTarget& target, sf::RenderStates states)const override;
	sf::FloatRect getBounds() const override;
	sf::Sprite getfondo() const;
	sf::FloatRect getGlobalBounds1() const;
	sf::FloatRect getGlobalBounds2() const;
	sf::FloatRect getGlobalBounds3() const;
	sf::FloatRect getGlobalBounds4() const;
	sf::FloatRect getGlobalBounds5() const;
	sf::FloatRect getGlobalBounds6() const;
	sf::FloatRect getGlobalBounds7() const;
	sf::FloatRect getGlobalBounds8() const;
	sf::FloatRect getGlobalBounds9() const;
	sf::FloatRect getGlobalBounds10() const;
	sf::FloatRect getGlobalBounds11() const;
	sf::FloatRect getGlobalBounds12() const;
	sf::FloatRect getGlobalBounds13() const;
	sf::FloatRect getGlobalBounds16() const;
	sf::FloatRect getGlobalBounds17() const;
	sf::Vector2f getposition1() const;
	sf::Vector2f getposition2() const;
	sf::Vector2f getposition3() const;
	sf::Vector2f getposition4() const;
	sf::Vector2f getposition5() const;
	sf::Vector2f getposition6() const;
	sf::Vector2f getposition7() const;
	sf::Vector2f getposition8() const;
	sf::Vector2f getposition9() const;
	sf::Vector2f getposition10() const;
	sf::Vector2f getposition11() const;
	sf::Vector2f getposition12() const;
	sf::Vector2f getposition13() const;
	sf::Vector2f getposition16() const;
	sf::Vector2f getposition17() const;
};
