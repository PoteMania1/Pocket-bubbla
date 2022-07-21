#pragma once
#include <SFML/Graphics.hpp>
#include "GamePlayable.h"
#include "Personaje.h"
#include "Puntos.h"
#include "Item.h"
#include "Nivel1.h"
#include "Enemigo.h"
#include "Enemigo2.h"
#include "Ataque.h"
#include "Hud.h"
#include "Vidas.h"
#include <list>

class GamePlay : public sf::Drawable , public GamePlayable
{
private:
	sf::Music music;
	Personaje _ash;
	Enemigo _enemy;
	Enemigo2 _enemy2;
	Enemigo _enemy3;
	Enemigo2 _enemy4;
	Nivel1 _nivel1;
	Item _frutas[10];
	bool _colision;
	//sf::Vector2f _preposPlataform;
	//sf::Vector2f _preposPlataform2;
	std::list<Ataque> _haduken;
	sf::SoundBuffer _bufferMonedas;
	sf::SoundBuffer _bufferMuerte;
	sf::SoundBuffer _bufferAtaque;
	sf::Sound _sound;
	Puntos _puntos;
	Hud _hud;
	Vidas _vidas;

public:
	GamePlay();
	void cmd();
	void update();
	void draw(sf::RenderTarget& target, sf::RenderStates states)const override;
	void movimientoPlataforma(sf::Sprite &plataforma, sf::Vector2f& preposs);
	int auxMovPlataform;
	void createBala(float positionX, float positionY, bool izqOder) override;
	void sonidos();
	void setVida();
	void setPuntos();
	void ColisionObst();
	void ColisionesAtaque(Enemigo&, Enemigo2&);
	void ColisionesEnemigos(Enemigo&, Enemigo2&);
	bool GameOver();
	int getvidas();
};

