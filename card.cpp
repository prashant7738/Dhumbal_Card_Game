//
// Created by sahbi on 8/16/2024.
//

#include "card.h"
#include <string>

void card::getcard(int value, std::string suit, sf::Sprite sprite) {
    this->value = value;
    this->suit = suit;
    this->img = sprite;
};