#include <iostream>
#include <SFML/Graphics.hpp>
#include "bot.h"
#include "card.h"
#include "function.h"
#include "player.h"

int playerscoreint=0;
int botscoreint=0;

int main() {
    label:

    
    sf::Texture textures[52];
    std::vector<card> deck(52);
    std::vector<card> throwndeck;
    function::deckcreation(deck,&textures);
    function::shuffle(deck);


    player player1(deck);
    bot bot1(deck);
    bool playerturn=true;

    sf::RenderWindow window(sf::VideoMode(1000, 670), "Dhumbal A Taas Game");

    sf::Font font;
    if (!font.loadFromFile("../card img/sample.ttf")) {
        std::cerr << "Error loading font\n";
        return -1;
    }

    // Create the button
    sf::RectangleShape button(sf::Vector2f(120, 50));
    button.setFillColor(sf::Color::Red);
    button.setPosition(850, 500);

    sf::Text buttonText("JHYAAP", font, 24);
    buttonText.setFillColor(sf::Color::White);
    buttonText.setPosition(
        button.getPosition().x + (button.getSize().x - buttonText.getLocalBounds().width) / 2,
        button.getPosition().y + (button.getSize().y - buttonText.getLocalBounds().height) / 2
    );

    sf::Text playerscore;
    playerscore.setFont(font);
    playerscore.setString(std::to_string(playerscoreint));             // Set the string to display
    playerscore.setCharacterSize(30);                  // Set the text size (in pixels)
    playerscore.setFillColor(sf::Color::Red);          // Set the text color
    playerscore.setPosition(20, 550  );

    sf::Text botscore;
    botscore.setFont(font);
    botscore.setString(std::to_string(botscoreint));             // Set the string to display
    botscore.setCharacterSize(30);                  // Set the text size (in pixels)
    botscore.setFillColor(sf::Color::Red);          // Set the text color
    botscore.setPosition(20, 20);

    while (window.isOpen()) {

        sf::Event event{};
        //std::cout<<i++;

        window.draw(button);
        window.draw(buttonText);


        if(playerturn) {
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
                if (event.type == sf::Event::MouseButtonPressed) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        int ex=player1.selectbymouse(window, deck, bot1, button,  buttonText, playerscoreint, botscoreint);
                        if(ex==0) {
                            playerturn=false;
                        }
                        else if (ex==1) {
                            playerturn=true;
                        }
                        else if (ex==2) {
                            goto label;
                        }

                    }
                }
            }
            window.clear();
            window.draw(button);
            window.draw(buttonText);
            window.draw(playerscore);
            window.draw(botscore);


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
            }

            // for (int i = 0; i < player1.throwncard.size(); i++) {
            //     player1.throwncard[i].img.setPosition(1000.f-100.f*(i+3), 250.f);
            //     window.draw(player1.throwncard[i].img);
            // }

        }

        else {

            window.clear();
            window.draw(button);
            window.draw(buttonText);
            window.draw(playerscore);
            window.draw(botscore);


            for(int i=0; i<player1.playerdeck.size(); i++) {
                player1.playerdeck[i].img.setPosition((i+1) * 100.f, 520.f);
                window.draw(player1.playerdeck[i].img);
                //std::cout << player1.playerdeck.size();
            }
            for (int i = 0; i < bot1.botdeck.size(); i++) {
                bot1.backview.setPosition((i + 1) * 100.f, 0.f);
                window.draw(bot1.backview);
            }
            for (int i = 0; i < player1.throwncard.size(); i++) {
                player1.throwncard[i].img.setPosition(1000.f-100.f*(i+3), 250.f);
                window.draw(player1.throwncard[i].img);
            }
            window.draw(player1.backview);
            if(bot1.handvalue()<=7) {
                bot1.jhyap(player1, playerscoreint , botscoreint);
                std::cout<<playerscoreint<<"\t"<<botscoreint<< std::endl;
                //sf::sleep(sf::seconds(10));
                goto label;
            }
            bot1.botthrow();
            playerturn=true;
            // for (int i = 0; i < bot1.botthrowncard.size(); i++) {
            //     bot1.botthrowncard[i].img.setPosition(1000.f-100.f*(i+3), 250.f);
            //     window.draw(bot1.botthrowncard[i].img);
            //     // std::cout<<bot1.botthrowncard[i].suit;
            //     // std::cout<<bot1.botthrowncard[i].value;
            // }

            // if (playerturn) {
            //     sf::sleep(sf::seconds(3));
            // }
            bot1.botdeck.push_back(bot1.selectCardFromThrownOrDeck(player1.throwncard,deck));
            bot1.arrange();
            std::cout<<bot1.handvalue();

        }

        window.display();
    }
    std::cout<< "hello";
    return 0;
}
