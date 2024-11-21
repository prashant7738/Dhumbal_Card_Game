//
// Created by sahbi on 8/16/2024.
//

#ifndef CARD_H
#define CARD_H
#include <string>
#include <SFML/Graphics.hpp>


class card {
public:
    int value;
    std::string suit;
    sf:: Sprite img;
    card()= default;
    void getcard( int v, std::string s, sf::Sprite i ) ;
    bool operator==(const card& other) const {
        return (suit == other.suit) && (value == other.value);
    }

    void clear() {
        value = 0;            // Set to a default or invalid value
        suit = "";            // Set to an empty string or other default
        img = sf::Sprite();   // Reset the sprite to a default state
    }
};



#endif //CARD_H
