#pragma once

#include <SFML/Graphics.hpp>

class Background {
private:
    sf::Texture texture;
    sf::Sprite sprite;

public:
    Background();
    void draw(sf::RenderWindow& window);
};

