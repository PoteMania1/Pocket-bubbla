#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <ctime>
#include "GamePlay.h"
#include "MainMenu.h"
#include "Vidas.h"
#include <list>


int main()
{
    std::srand((unsigned)std::time(0));

    //inicializacion de la ventana
    sf::RenderWindow window(sf::VideoMode(800, 600), "Pocket Bubbla!");
    window.setFramerateLimit(60);
    MainMenu mainmenu(800, 600);
    GamePlay game;
    Puntos puntos;
    //Vidas vida;
    int inicio = 0;
    int x = 0;
    bool play = false;
    bool status = false;
    bool score = false;


    //Game Loop (update del juego)
    while (window.isOpen())
    {
        //ReadInput Actualiza los estados de los perifericos de entrada
        //Leer la cola de mensajes
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (!play) {
                x = 0;
                game.setVida();
                game.setPuntos();
            }
            if (event.type == sf::Event::Closed)
                window.close();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                window.close();
            switch (event.type)
            {
            case sf::Event::KeyReleased:

                switch (event.key.code)
                {
                case sf::Keyboard::Up:
                    status = false;
                    score = false;
                    if (!status && !play && !score) {
                        mainmenu.MoveUp();
                    }
                    break;

                case sf::Keyboard::Down:
                    status = false;
                    score = false;
                    if (!status && !play && !score) {
                        mainmenu.MoveDown();
                    }
                    break;

                case sf::Keyboard::Return:
                    switch (mainmenu.MainMenuPressed())
                    {
                    case 0:
                        std::cout << "Play button has been pressed" << std::endl;
                        play = true;
                        mainmenu.Stop();
                        break;
                    case 1:
                        std::cout << "Score button has been pressed" << std::endl;
                        score = true;
                        break;
                    case 2:
                        std::cout << "about button has been pressed" << std::endl;
                        status = true;
                        break;
                    case 3:
                        window.close();
                        break;
                    }

                    break;
                }

                break;

            case sf::Event::Closed:
                window.close();

                break;

            }
        }

        // CMD - Joy
        if (play && game.GameOver() == false) {
            game.cmd();
        }
        // Update - Actualiza los estados del juego
        if (play && game.GameOver() == false) {
            game.update();
            if (game.GameOver() && x == 0) {
                puntos.setPuntos(game.getpuntos());
                std::cout << puntos.getPuntos() << "\n";
                puntos.GuardarEnDisco();
                play = false; 
                x++;
            }
        }

        window.clear();

        // Draw
        if(!play){
            mainmenu.draw(window,status,score);
            //mainmenu.SonidoFondo(play);
        }
        if(play && game.GameOver()==false){
            window.draw(game);
        }

        // Display - Flip
        window.display();

    }

    //Liberacion del Juego

    return 0;
}