//
// Created by sahbi on 8/17/2024.
//

#ifndef BOT_H
#define BOT_H
#include <vector>
#include "card.h"


class bot {
public:
    std::vector<card> botdeck;
    std::vector<card> botthrowncard;
    std::vector<card> botselectedcard;
    sf::Sprite backview;
    sf::Texture backviewtexture;

     bot(std::vector<card>& deck){
        for(int i=0; i<7; i++) {
            botdeck.push_back(deck[0]);
            deck.erase(deck.begin());
        }
        arrange();
        deckview();
    };

    int handvalue() const;
    void botthrow();
    void remove();
    void arrange();
    bool findsamevaluecarddiffsuit();
    bool findconsecutivecardsamesuit();
    bool validcard();
    bool jhyap();
    void deckview();




};



#endif //BOT_H
