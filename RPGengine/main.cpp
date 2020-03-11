#include <SFML/Graphics.hpp>

#include "StateStack.h"
#include "subworldState.h"
#include "mainMenuState.h"

#include "Party.h"

#include <MapLoader.h>

#define TILE_WIDTH 32

int main() {
    bool isMenu = true;
    bool fullscreen = false;
    std::string pathOne = "resources/images/filler/cat200x200_1.png";
    std::string pathTwo = "resources/images/filler/cat200x200_2.png";
    //sf::View mainView(sf::Vector2f(1920, 1080), sf::Vector2f(1920, 1080));
    sf::RenderWindow myWindow(sf::VideoMode(TILE_WIDTH * 50, TILE_WIDTH * 25), "zEngine");
    //myWindow.setView(mainView);
    myWindow.setVerticalSyncEnabled(1);
    StateStack sStack;
    sStack.push(new mainMenuState(pathOne));

    sf::Clock updateClock;

    while (myWindow.isOpen()) {
        sf::Event event;
        while (myWindow.pollEvent(event)) {
            if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) {
                myWindow.close();
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return) {
                if (isMenu) {
                    sStack.push(new subworldState("resources/maps/", "rpgtest.tmx"));
                    isMenu = false;
                } else {
                    sStack.pop();
                    isMenu = true;
                }
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::P) {
                std::cin.get();
            }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::F9) {
                    fullscreen ^= 1;
                    myWindow.create(sf::VideoMode(TILE_WIDTH * 50, TILE_WIDTH * 25), "zEngine", (fullscreen ? sf::Style::Fullscreen : sf::Style::Default /*| sf::Style::Close*/));
                    myWindow.setVerticalSyncEnabled(1);
                    myWindow.setMouseCursorVisible(0);
                }
            }
        }

        sf::Time updateTimer = updateClock.getElapsedTime();
        if (updateTimer.asMilliseconds() >= 17) {
            sStack.update();
            updateClock.restart();
        }

        myWindow.clear();
        sStack.render(myWindow);
        myWindow.display();
    }
}