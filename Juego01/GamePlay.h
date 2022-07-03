#pragma once
#include <SFML/Graphics.hpp>
#include "GamePlayable.h"
#include "Personaje.h"
#include "Item.h"
#include "Nivel.h"
#include "Obstaculo.h"
#include "Enemigo.h"
#include "Enemigo2.h"
#include "Ataque.h"
#include <list>

class GamePlay : public sf::Drawable , public GamePlayable
{
private:
	sf::Music music;
	Personaje _ash;
	Item _fruta;
	Item _frutas[10];
	Nivel _nivel1;
	Obstaculo _plataforma;
	sf::Sprite _plataformaD[25];
	Enemigo _enemy;
	Enemigo2 _enemy2;
	bool _colision;
	//Enemigo enemy[5];   ///MUCHOS WARGREYMONES
	sf::Vector2f _preposPlataform;
	sf::Vector2f _preposPlataform2;
	std::list<Ataque> _haduken;
	std::list<Item> _Frutas;
	sf::SoundBuffer _bufferMonedas;
	sf::SoundBuffer _bufferMuerte;
	sf::SoundBuffer _bufferPasos;
	sf::Sound _sound;

public:
	GamePlay();
	void cmd();
	sf::Sprite getSprite1();
	void update();
	void draw(sf::RenderTarget& target, sf::RenderStates states)const override;
	void movimientoPlataforma(sf::Sprite &plataforma, sf::Vector2f& preposs);
	int auxMovPlataform;
	void createBala(float positionX, float positionY, bool izqOder) override;
	void sonidos();
};

