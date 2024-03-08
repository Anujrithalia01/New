#pragma once

#include <SFML/Graphics.hpp>
#include "Background.h" // Include background.h for Background class
#include <SFML/System.hpp>

class Game {
private:
    sf::RenderWindow window;
    Background backgrund;
    // Add other necessary variables and functions here

public:
    Game();
    void run();
  
};

