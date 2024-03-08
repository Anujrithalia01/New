#include "Background.h"


Background::Background() {
    if (!texture.loadFromFile("images/background.png")) {
        // handle error
    }

    sprite.setTexture(texture);
}

void Background::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}
