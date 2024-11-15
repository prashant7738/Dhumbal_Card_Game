#include <iostream>
#include <SFML/Graphics.hpp>
#include "bot.h"
#include "card.h"
#include "function.h"
#include "player.h"



int main() {
    sf::Texture textures[52];
    std::vector<card> deck(52);
    std::vector<card> throwndeck;
    function::deckcreation(deck,&textures);
    function::shuffle(deck);
    player player1(deck);
    bot bot1(deck);
    bool playerturn=true;

    sf::RenderWindow window(sf::VideoMode(1000, 670), "Dhumbal A Taas Game");

    int i=0;
    while (window.isOpen()) {
        sf::Event event{};
        //std::cout<<i++;

        if(playerturn) {
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
                if (event.type == sf::Event::MouseButtonPressed) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        playerturn=player1.selectbymouse(window, deck, bot1);
                    }
                }
            }
            window.clear();
            for(int i=0; i<player1.playerdeck.size(); i++) {
                window.draw(player1.playerdeck[i].img);
               // std::cout << player1.playerdeck.size();
            }
            for (int i = 0; i < bot1.botdeck.size(); i++) {
                sf::Sprite tempBackview = bot1.botdeck[i].img;  // Create a temporary copy
                tempBackview.setPosition((i + 1) * 100.f, 0.f);
                window.draw(tempBackview);
            }
            window.draw(player1.backview);

            for (int i = 0; i < bot1.botthrowncard.size(); i++) {
                bot1.botthrowncard[i].img.setPosition(1000.f-100.f*(i+3), 250.f);
                window.draw(bot1.botthrowncard[i].img);
                std::cout<<bot1.botthrowncard[i].suit;
                std::cout<<bot1.botthrowncard[i].value;
            }

            // for (int i = 0; i < player1.throwncard.size(); i++) {
            //     player1.throwncard[i].img.setPosition(1000.f-100.f*(i+3), 250.f);
            //     window.draw(player1.throwncard[i].img);
            // }
        }

        else {
            window.clear();
            for(int i=0; i<player1.playerdeck.size(); i++) {
                player1.playerdeck[i].img.setPosition((i+1) * 100.f, 520.f);
                window.draw(player1.playerdeck[i].img);
                //std::cout << player1.playerdeck.size();
            }
            for (int i = 0; i < bot1.botdeck.size(); i++) {
                sf::Sprite tempBackview = bot1.botdeck[i].img;  // Create a temporary copy
                tempBackview.setPosition((i + 1) * 100.f, 0.f);
                window.draw(tempBackview);
            }
            window.draw(player1.backview);
            bot1.botthrow();
            playerturn=true;
            // for (int i = 0; i < bot1.botthrowncard.size(); i++) {
            //     bot1.botthrowncard[i].img.setPosition(1000.f-100.f*(i+3), 250.f);
            //     window.draw(bot1.botthrowncard[i].img);
            //     std::cout<<bot1.botthrowncard[i].suit;
            //     std::cout<<bot1.botthrowncard[i].value;
            // }
            for (int i = 0; i < player1.throwncard.size(); i++) {
                player1.throwncard[i].img.setPosition(1000.f-100.f*(i+3), 250.f);
                window.draw(player1.throwncard[i].img);
            }
            bot1.botdeck.push_back(deck.front());
            deck.erase(deck.begin());
            bot1.arrange();


        }

        window.display();
    }
    std::cout<< "hello";
    return 0;
}
