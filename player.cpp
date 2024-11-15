//
// Created by sahbi on 8/16/2024.
//

#include "player.h"
#include <functional>

bool player::turn = true;


int player::handvalue() const {
    int value=0;
    for(int i=0; i<7; i++) {
        value+=playerdeck[i].value;
    }
    return value;
}
void player::remove() {
    for (const auto& thrownCard : throwncard) {
        for (size_t j = 0; j < playerdeck.size(); ++j) {
            isselected[j] = false;
            if (playerdeck[j].value == thrownCard.value && playerdeck[j].suit == thrownCard.suit) {
                playerdeck.erase(playerdeck.begin() + j);  // Remove the card
            }
        }
    }
}



void player::arrange() {
    for(int i=0; i<7; i++) {
        for(int j=i; j<7; j++) {
            if(playerdeck[i].value>playerdeck[j].value) {
                card temp = playerdeck[i];
                playerdeck[i]=playerdeck[j];
                playerdeck[j]=temp;
            }
            for(int i=0; i<playerdeck.size(); i++) {
                playerdeck[i].img.setPosition((i+1) * 100.f, 520.f);
            }
        }
    }
}

void player::unselectall() {
    for(int i=0; i<playerdeck.size(); i++) {
        isselected[i]=false;
        selectedcard.clear();
    }
    for(int i=0; i<playerdeck.size(); i++) {
        playerdeck[i].img.setPosition((i+1) * 100.f, 520.f);
    }
}

bool player::validcard() {


    bool samevalue = true, sequence = true;
    int firstVal =selectedcard[0].value;
    std::string firstSuit = selectedcard[0].suit;

    // Check if all cards have the same value
    for (const auto& c : selectedcard) {
        if (c.value != firstVal) {
            samevalue = false;
            break;
        }
    }

    // Check if the cards form a sequence with the same suit
    if (selectedcard.size() >= 3) {
        // Sort cards by value
        std::sort(selectedcard.begin(), selectedcard.end(), [](const card& c1, const card& c2) {
            return c1.value < c2.value;
        });

        for (std::size_t i = 1; i < selectedcard.size(); ++i) {
            if (selectedcard[i].suit != firstSuit || selectedcard[i].value != selectedcard[i-1].value + 1) {
                sequence = false;
                break;
            }
        }
    } else {
        sequence = false;
    }
    return sequence || samevalue;
}

bool player::selectbymouse(sf::RenderWindow& window, std::vector<card> &deck,const bot b) {
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);



    // Check each card for selection/deselection
    for (int i = 0; i < playerdeck.size(); ++i) {
        if (playerdeck[i].img.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
            isselected[i] = !isselected[i];  // Toggle selection state

            if (isselected[i]) {
                // If selected, move the card and add to selectedcard
                playerdeck[i].img.setPosition(100.f + i * 100.f, 500.f);
                selectedcard.push_back(playerdeck[i]);
                std::cout << "Card selected! Suit: " << playerdeck[i].suit << ", Value: " << playerdeck[i].value << std::endl;
                return true;
            } else {
                // If deselected, remove from selectedcard
                selectedcard.erase(std::remove(selectedcard.begin(), selectedcard.end(), playerdeck[i]), selectedcard.end());
                std::cout << "Card deselected! Suit: " << playerdeck[i].suit << ", Value: " << playerdeck[i].value << std::endl;
                playerdeck[i].img.setPosition((i+1) * 100.f, 520.f);
                return true;
            }

            break;  // Stop checking other cards once one is selected/deselected
        }
    }

    // Check if the backview area is clicked for confirming the throw
    if (backview.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
        if ((validcard() || selectedcard.size()==1) && selectedcard.size()!=0) {
            // Valid card selected, perform actions
            throwncard = selectedcard;
            selectedcard.clear();
            remove();
            playerdeck.push_back(deck.front());
            deck.erase(deck.begin());
            arrange();
            for (int i = 0; i < playerdeck.size(); i++) {
                playerdeck[i].img.setPosition((i + 1) * 100.f, 520.f);
            }
            turn=false;
            return false;  // Valid card selected, exit the loop
        } else {
            std::cout << "Invalid card selection!" << std::endl;
            return true;  // Invalid card, continue loop
            //turn=true;
        }
    }



    // else {
    //     int thrownsize =b.botthrowncard.size();
    //     for(int i=0; i<thrownsize ; i++) {
    //         if (b.botthrowncard[i].img.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
    //             if ((validcard() || selectedcard.size()==1) && selectedcard.size()!=0) {
    //                 // Valid card selected, perform actions
    //                 throwncard = selectedcard;
    //                 selectedcard.clear();
    //                 remove();
    //                 playerdeck.push_back(b.botthrowncard[i]);
    //                 arrange();
    //                 for (int i = 0; i < playerdeck.size(); i++) {
    //                     playerdeck[i].img.setPosition((i + 1) * 100.f, 520.f);
    //                 }
    //                 return true;  // Valid card selected, exit the loop
    //             } else {
    //                 std::cout << "Invalid card selection!" << std::endl;
    //                 return false;  // Invalid card, continue loop
    //             }
    //         }
    //     }
    //
    // }
    //
     return true;  // No valid selection made
}

void player::deckview() {
    if (!backviewtexture.loadFromFile("../card img/jocker/backview.jpg")) {
        std::cout << "Error loading texture" << std::endl;
        return; // Exit if the texture loading fails
    }
    backview.setTexture(backviewtexture);
    backview.setScale(0.15f, 0.15f);
    backview.setPosition(840.f, 240.f);
}








