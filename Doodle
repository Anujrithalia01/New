#include<iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <time.h>

using namespace sf;

struct point{
    int px, py;
};

int main()
{
    srand(time(0));

    RenderWindow app(VideoMode(530, 833), "My Game!");
    app.setFramerateLimit(60);
    app.setKeyRepeatEnabled(false);

    bool hasJumped = false;
    Texture playrr, backgrund, platfrm;

    playrr.loadFromFile("images/doodle.png");
    backgrund.loadFromFile("images/background.png");
    platfrm.loadFromFile("images/platform.png");

    Sprite splat, sback, splayer;
    splat.setTexture(platfrm);
    sback.setTexture(backgrund);
    splayer.setTexture(playrr);

    point plat[20];

    for (int i = 0; i < 15; i++) {
        plat[i].px = rand() % 530;
        plat[i].py = rand() % 833;
    }
    int chx = 100, chy = 400, height = 30;
    float dx = 0, dy = 0; 

    Font font;
    if (!font.loadFromFile("images/dj.ttf")) {
        std::cout << "Error: Font can't be load" << std::endl;
    }

    Text txt;
    txt.setFont(font);
    txt.setFillColor(Color::Red);
    txt.setString("Game Over");
    txt.setPosition(100 , 100);
    txt.setCharacterSize(40);
    

    while (app.isOpen()) {
        Event evnt; 

        while (app.pollEvent(evnt)) {
            if (evnt.type == Event::Closed)
                app.close();

            if (evnt.type == Event::KeyPressed) {

                
                if (evnt.key.code == Keyboard::Up && !hasJumped) {
                    // Perform the jump action
                    dy = -10;
                    hasJumped = true; // Set the jump flag
                }
            }
              else  if (evnt.type == Event::KeyReleased) {
                      if (evnt.key.code == Keyboard::Up) {
                    // Reset the jump flag when the key is released
                    hasJumped = false;
                      }
                 
              }
        }
        if (Keyboard::isKeyPressed(Keyboard::Right)) chx += 3;
        if (Keyboard::isKeyPressed(Keyboard::Left)) chx -= 3;
        
        dy += 0.2;
        chy += dy;

        if (chy > 800) {
          
            app.draw(txt);
            dy = 0;
        }

        if (chy < height) {
            for (int i = 0; i < 15; i++) {
                chy = height;
                plat[i].py = plat[i].py - dy;

                if (plat[i].py > 833) { plat[i].py = 0; plat[i].px = rand() % 530;}
            }

        }

        for (int i = 0; i < 15; i++) {
            if ((chx + 50 > plat[i].px) && (chx + 20 < plat[i].px + 68) && (chy + 70 > plat[i].py) && (chy + 70 < plat[i].py + 14) && (dy > 0)) {
                dy = -5; 
            }
        }

        splayer.setPosition(chx, chy);

        app.draw(sback);
        app.draw(splayer);
       
        for (int i = 0; i < 15; i++) {
            splat.setPosition(plat[i].px, plat[i].py);
            app.draw(splat);
        }

        app.display();
        
    }





    return 0;
}
