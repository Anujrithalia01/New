#include "Game.h"
#include "Background.h" // Include background.h for Background class
#include <time.h>
#include <SFML/System.hpp>
#include <iostream>

Game::Game() : window(sf::VideoMode(530, 833), "My Game!") {
    window.setFramerateLimit(60);
    window.setKeyRepeatEnabled(false);
}



void Game::run() {
    bool hasJumped = false;
    int score =0;
    bool gameover = false;
    sf:: Clock gameOverClock;

    sf::Texture playerTexture, platformTexture;
    playerTexture.loadFromFile("images/doodle.png");
    platformTexture.loadFromFile("images/platform.png");

    sf::Sprite playerSprite, platformSprite;
    playerSprite.setTexture(playerTexture);
    platformSprite.setTexture(platformTexture);

    struct point {
        int px, py;
    };

    point plat[20];

    for (int i = 0; i < 15; i++) {
        plat[i].px = rand() % 530;
        plat[i].py = rand() % 833;
    }

    int chx = 100, chy = 400, height = 30;
    float dx = 0, dy = 0;

    sf::Font font;
    if (!font.loadFromFile("images/Copyduck.ttf")) {
        // handle error
        std::cout << "Font is not loading" << std::endl;
    }
    
    
    sf::Text txt;
    txt.setFont(font);
    txt.setFillColor(sf::Color::Red);
    txt.setString("Game\nOver!");
    txt.setPosition((window.getSize().x / 2.f) -140, (window.getSize().y / 2.f) - 170);
    txt.setCharacterSize(100);
    txt.setStyle(sf::Text::Bold);


    sf::Font font2;
    if (!font2.loadFromFile("images/Copyduck.ttf")) {
        std::cout << "Font2 is not loading" << std::endl;
    }

    sf::Text txt2;
    txt2.setFont(font2);
    txt2.setFillColor(sf::Color::Red);
   
    txt2.setPosition(0, 0);
    txt2.setCharacterSize(30);
    txt2.setStyle(sf::Text::Italic);

   

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Up && !hasJumped) {
                    dy = -6;
                    hasJumped = true;
                }
            }
            else if (event.type == sf::Event::KeyReleased) {
                if (event.key.code == sf::Keyboard::Up) {
                    hasJumped = false;
                }
            }
        }

       

        if (!gameover) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) chx += 3;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) chx -= 3;

            dy += 0.2;
            chy += dy;

            if (chy > 800) {
                gameover = true;
                gameOverClock.restart();
            }

            if (chy < height) {
                for (int i = 0; i < 15; i++) {
                    chy = height;
                    plat[i].py = plat[i].py - dy;
                    if (plat[i].py > 833) {
                        plat[i].py = 0;
                        plat[i].px = rand() % 530;
                    }
                }
            }

            for (int i = 0; i < 15; i++) {
                if ((chx + 50 > plat[i].px) && (chx + 20 < plat[i].px + 68) && (chy + 70 > plat[i].py) && (chy + 70 < plat[i].py + 14) && (dy > 0)) {
                    dy = -3;
                    txt2.setString("Score: " + std::to_string(score));
                    score++;
                }
            }
        }

        playerSprite.setPosition(chx, chy);

        window.clear();
        backgrund.draw(window);
        window.draw(playerSprite);
        window.draw(txt2);

        for (int i = 0; i < 15; i++) {
            platformSprite.setPosition(plat[i].px, plat[i].py);
            window.draw(platformSprite);
        }

        if (gameover) {
            window.clear();
            window.draw(txt);


            if (gameOverClock.getElapsedTime().asSeconds() > 10.0f) {
                window.close();
            }
        }

        window.display();
    }
}
