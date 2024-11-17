//
// Created by sahbi on 8/16/2024.
//

#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <vector>

#include "bot.h"
#include "card.h"

class bot;
class player {
public:
    std::vector<card> playerdeck;
    std::vector<card> selectedcard;
    std::vector<card> throwncard;
    std::vector<bool> isselected={false,false,true,false,false,false,false};
    sf::Sprite backview;
    sf::Texture backviewtexture;
    int score;


    player(std::vector<card>& deck){
        for(int i=0; i<7; i++) {
            playerdeck.push_back(deck[0]);
            deck.erase(deck.begin());
        }
        arrange();
        for(int i=0; i<7; i++) {
            playerdeck[i].img.setPosition((i+1) * 100.f, 520.f);
        }
        deckview();
    };
    int handvalue() const;
    void remove();
    void arrange();
    void unselectall();
    bool validcard();
    int selectbymouse(sf::RenderWindow& window,std::vector<card>& deck,const bot b , const sf::RectangleShape& button, const sf::Text& buttonText, int &playerscoreint, int &botscoreint );
    void deckview();
    int jhyap(bot b, int &pscore, int &bscore);
    card takencard;
    static bool turn;


};



#endif //PLAYER_H
