//
// Created by sahbi on 8/17/2024.
//

#include "bot.h"

#include <iostream>
#include <unordered_map>

#include "player.h"

int bot::handvalue()  {
    int value=0;
    for(int i=0; i<botdeck.size(); i++) {
        value+=botdeck[i].value;
    }
    return value;
}

void bot::remove() {
    for (int i=0; i<botthrowncard.size(); i++) {
        for(int j=0; j<botdeck.size(); j++) {
            if(botthrowncard[i].value == botdeck[j].value && botthrowncard[i].suit == botdeck[j].suit) {
                botdeck.erase(botdeck.begin()+j);
            }
        }
    }
}


void bot::arrange() {
    for(int i=0; i<7; i++) {
        for(int j=i; j<7; j++) {
            if(botdeck[i].value>botdeck[j].value) {
                card temp = botdeck[i];
                botdeck[i]=botdeck[j];
                botdeck[j]=temp;
            }
        }
    }
}

bool bot::findsamevaluecarddiffsuit() {
    std::unordered_map<int, std::vector<card>> cardMap;
    botselectedcard.clear(); // Clear the vector to ensure no previous data is stored
    int maxValue = -1;      // To store the maximum value found

    // Populate the unordered_map with cards by value
    for (const auto& card : botdeck) {
        cardMap[card.value].push_back(card);
    }

    // Find the maximum value with different suits
    for (const auto& pair : cardMap) {
        const auto& cards = pair.second;
        if (cards.size() > 1) { // If more than one card with the same value exists
            for (size_t i = 0; i < cards.size(); ++i) {
                for (size_t j = i + 1; j < cards.size(); ++j) {
                    if (cards[i].suit != cards[j].suit) {
                        // If the current value is greater than the maxValue, update maxValue and selectedCards
                        if (pair.first > maxValue) {
                            maxValue = pair.first;
                            botselectedcard.clear(); // Clear the vector for the new max value
                        }
                        if (pair.first == maxValue) {
                            // Add all cards with the same max value and different suits
                            if (std::find(botselectedcard.begin(), botselectedcard.end(), cards[i]) == botselectedcard.end()) {
                                botselectedcard.push_back(cards[i]);
                            }
                            if (std::find(botselectedcard.begin(), botselectedcard.end(), cards[j]) == botselectedcard.end()) {
                                botselectedcard.push_back(cards[j]);
                            }
                        }
                    }
                }
            }
        }
    }

    return !botselectedcard.empty(); // Return true if any cards were found
}



bool bot::findconsecutivecardsamesuit() {
    // Sort the deck by suit and then by value
    std::sort(botdeck.begin(), botdeck.end(), [](const card& a, const card& b) {
        if (a.suit == b.suit)
            return a.value < b.value;
        return a.suit < b.suit;
    });

    botselectedcard.clear(); // Clear the vector to ensure no previous data is stored

    std::vector<card> currentSequence;
    bool foundSequence = false;

    for (size_t i = 0; i < botdeck.size(); ++i) {
        if (i == 0 || botdeck[i].suit == botdeck[i - 1].suit) {
            // Continue the current sequence if suits are the same
            if (currentSequence.empty() || botdeck[i].value == currentSequence.back().value + 1) {
                currentSequence.push_back(botdeck[i]);
            } else {
                // Check if the current sequence has 3 or more cards and store it
                if (currentSequence.size() >= 3) {
                    botselectedcard.insert(botselectedcard.end(), currentSequence.begin(), currentSequence.end());
                    foundSequence = true;
                }
                // Start a new sequence
                currentSequence = {botdeck[i]};
            }
        } else {
            // Check if the current sequence has 3 or more cards and store it
            if (currentSequence.size() >= 3) {
                botselectedcard.insert(botselectedcard.end(), currentSequence.begin(), currentSequence.end());
                foundSequence = true;
            }
            // Reset for the new suit
            currentSequence.clear();
            currentSequence.push_back(botdeck[i]);
        }
    }

    // Check if the last sequence has 3 or more cards and store it
    if (currentSequence.size() >= 3) {
        botselectedcard.insert(botselectedcard.end(), currentSequence.begin(), currentSequence.end());
        foundSequence = true;
    }

    return foundSequence; // Return true if at least one valid sequence was found
}

bool bot::validcard() {

    bool samevalue = true, sequence = true;
    int firstVal =botselectedcard[0].value;
    std::string firstSuit = botselectedcard[0].suit;

    // Check if all cards have the same value
    for (const auto& c : botselectedcard) {
        if (c.value != firstVal) {
            samevalue = false;
            break;
        }
    }

    // Check if the cards form a sequence with the same suit
    if (botselectedcard.size() >= 3) {
        // Sort cards by value
        std::sort(botselectedcard.begin(), botselectedcard.end(), [](const card& c1, const card& c2) {
            return c1.value < c2.value;
        });

        for (std::size_t i = 1; i < botselectedcard.size(); ++i) {
            if (botselectedcard[i].suit != firstSuit || botselectedcard[i].value != botselectedcard[i-1].value + 1) {
                sequence = false;
                break;
            }
        }
    } else {
        sequence = false;
    }

    return sequence || samevalue;
}

void bot::botthrow() {
    if(findconsecutivecardsamesuit() && (botselectedcard.size() >= 3 || (botselectedcard[0].value >> 1)) ) {
        botthrowncard=botselectedcard;
        botselectedcard.clear();
        arrange();
    }
    else if(findsamevaluecarddiffsuit() && (botselectedcard.size() >= 2 || (botselectedcard[0].value >> 2))) {
        botthrowncard=botselectedcard;
        botselectedcard.clear();
        arrange();
    }
    else {
        botthrowncard.clear();
        arrange();
        botthrowncard.push_back(botdeck.back());
    }
    remove();

}

void bot::jhyap(player p, int &pscore, int &bscore) {
    if(p.handvalue()<= handvalue()) {
        bscore+=35+handvalue();
        pscore+=0;
    }
    else {
        bscore+=0;
        pscore+=p.handvalue();
    }
}
void bot::deckview() {
    if (!backviewtexture.loadFromFile("../card img/jocker/backview.jpg")) {
        std::cout << "Error loading texture" << std::endl;
        return; // Exit if the texture loading fails
    }
    backview.setTexture(backviewtexture);
    backview.setScale(0.1f, 0.1f);
    backview.setPosition(0.f, 0.f);
}



card bot::selectCardFromThrownOrDeck(std::vector<card>& throwncard, std::vector<card>& deck) {
    // Helper lambda to check if adding a card forms a sequence of 3 cards of the same suit
    auto formsSequenceSameSuit = [&](const card& card) {
        std::vector<int> values;
        for (const auto& c : botdeck) {
            if (c.suit == card.suit) { // Consider only cards of the same suit
                values.push_back(c.value);
            }
        }
        values.push_back(card.value);
        std::sort(values.begin(), values.end());

        // Check for a sequence of 3
        for (size_t i = 0; i + 2 < values.size(); ++i) {
            if (values[i + 1] == values[i] + 1 && values[i + 2] == values[i] + 2) {
                return true;
            }
        }
        return false;
    };

    // Step 1: Check for a card that forms a sequence of 3 cards of the same suit
    for (const auto& card : throwncard) {
        if (formsSequenceSameSuit(card)) {
            return card;
        }
    }

    // Step 2: Check for a card with the same value but different suit
    for (const auto& thrown : throwncard) {
        for (const auto& bot : botdeck) {
            if (thrown.value == bot.value && thrown.suit != bot.suit) {
                return thrown;
            }
        }
    }

    // Step 3: Take a card from the deck
    card s=deck.front();
    deck.erase((deck.begin()));
    return s;

}





