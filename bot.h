//
// Created by sahbi on 8/17/2024.
//

#ifndef BOT_H
#define BOT_H
#include <vector>
#include "card.h"
#include "player.h"

class player;
class bot {
public:
    std::vector<card> botdeck;
    std::vector<card> botthrowncard;
    std::vector<card> botselectedcard;
    sf::Sprite backview;
    sf::Texture backviewtexture;
    int score;

     bot(std::vector<card>& deck){
        for(int i=0; i<7; i++) {
            botdeck.push_back(deck.front());
            deck.erase(deck.begin());
        }
        arrange();
        deckview();
    };

    int handvalue() ;
    void botthrow();
    void remove();
    void arrange();
    bool findsamevaluecarddiffsuit();
    bool findconsecutivecardsamesuit();
    bool validcard();
    void jhyap(player p, int &pscore, int &bscore );
    void deckview();
    card selectCardFromThrownOrDeck(std::vector<card>& throwncard, std::vector<card>& deck);




};



#endif //BOT_H
