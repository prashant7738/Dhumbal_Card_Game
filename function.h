//
// Created by sahbi on 8/16/2024.
//

#ifndef FUNCTION_H
#define FUNCTION_H
#include <vector>
#include <random>

#include "card.h"
#include "paths.h"

namespace function {
    void deckcreation( std::vector<card> & deck, sf::Texture(* textures)[52]) {
        int count = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 1; j < 14; j++) {
                if (!(*textures)[count].loadFromFile(cardpaths[i][j])) {
                    std::cout << "Error loading texture: " << cardpaths[i][j] << std::endl;
                }
                sf::Sprite sprite;
                sprite.setTexture((*textures)[count]);
                sprite.scale(0.1f, 0.1f);

                deck[count].getcard(j, cardpaths[i][0], sprite);
                count++;
            }
        }
    }

    void shuffle(std::vector<card>& DECK) {
        std::random_device rd;  // Obtain a random number from hardware
        std::mt19937 g(rd());   // Seed the generator
        std::shuffle(DECK.begin(), DECK.end(), g);  // Shuffle the deck
    }

    card takefromdeck (std::vector<card> & DECK) {
        card temp=DECK[0];
        DECK.erase(DECK.begin());
        return temp;
    }

    std::vector<card> emptydeck(std::vector<card>  card) {
        shuffle(card);
        return card;
    }



}

#endif //FUNCTION_H
