#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "bot.h"
#include "card.h"
#include "function.h"
#include "player.h"

int main() {
target:
    int playerscoreint = 0;
    int botscoreint = 0;

label:
    sf::Texture textures[52];
    std::vector<card> deck(52);
    std::vector<card> throwndeck;
    function::deckcreation(deck, &textures);
    function::shuffle(deck);

    player player1(deck);
    bot bot1(deck);
    bool playerturn = true;

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
    playerscore.setString(std::to_string(playerscoreint)); // Set the string to display
    playerscore.setCharacterSize(30); // Set the text size (in pixels)
    playerscore.setFillColor(sf::Color::Red); // Set the text color
    playerscore.setPosition(20, 525);

    sf::Text botscore;
    botscore.setFont(font);
    botscore.setString(std::to_string(botscoreint)); // Set the string to display
    botscore.setCharacterSize(30); // Set the text size (in pixels)
    botscore.setFillColor(sf::Color::Red); // Set the text color
    botscore.setPosition(20, 20);

    sf::Text hvalue;
    hvalue.setFont(font);
    hvalue.setCharacterSize(18); // Set the text size (in pixels)
    hvalue.setFillColor(sf::Color::Red); // Set the text color
    hvalue.setPosition(60, 625);

    while (window.isOpen()) {
        sf::Event event{};
        if (playerturn) {
            hvalue.setString(std::to_string(player1.handvalue())); // Set the string to display
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
                if (event.type == sf::Event::MouseButtonPressed) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        int ex = player1.selectbymouse(window, deck, bot1, button, buttonText, playerscoreint,
                                                       botscoreint);
                        if (ex == 0) {
                            playerturn = false;
                            hvalue.setString(std::to_string(player1.handvalue())); // Set the string to display
                        } else if (ex == 1) {
                            playerturn = true;
                        } else if (ex == 2) {
                            playerscore.setString(std::to_string(playerscoreint)); // Set the string to display
                            botscore.setString(std::to_string(botscoreint)); // Set the string to display
                            sf::Text jhyaap;
                            jhyaap.setFont(font);
                            jhyaap.setString("PLAYER  CALLED  JHYAAP"); // Set the string to display
                            jhyaap.setCharacterSize(25); // Set the text size (in pixels)
                            jhyaap.setFillColor(sf::Color::Red); // Set the text color
                            jhyaap.setPosition(250, 275);
                            window.clear();
                            window.draw(jhyaap);
                            window.draw(button);
                            window.draw(buttonText);
                            window.draw(playerscore);
                            window.draw(botscore);
                            window.draw(hvalue);

                            for (int i = 0; i < player1.playerdeck.size(); i++) {
                                window.draw(player1.playerdeck[i].img);
                                // std::cout << player1.playerdeck.size();
                            }
                            for (int i = 0; i < bot1.botdeck.size(); i++) {
                                sf::Sprite tempBackview = bot1.botdeck[i].img; // Create a temporary copy
                                tempBackview.setPosition((i + 1) * 100.f, 0.f);
                                window.draw(tempBackview);
                            }
                            window.draw(player1.backview);

                            for (int i = 0; i < bot1.botthrowncard.size(); i++) {
                                bot1.botthrowncard[i].img.setPosition(1000.f - 100.f * (i + 3), 250.f);
                                window.draw(bot1.botthrowncard[i].img);
                            } {
                                bool waitingForC = true;

                                sf::Text con;
                                con.setFont(font);
                                con.setString("press c to continue"); // Set the string to display
                                con.setCharacterSize(20); // Set the text size (in pixels)
                                con.setFillColor(sf::Color::Red); // Set the text color
                                con.setPosition(810, 20);
                                window.draw(con);
                                window.display();

                                while (waitingForC) {
                                    while (window.pollEvent(event)) {
                                        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::C) {
                                            waitingForC = false; // Exit the loop when 'C' is pressed
                                        } if (event.type == sf::Event::Closed) {
                                            window.close();
                                            waitingForC = false; // Exit the loop
                                        }
                                    }
                                }
                            }
                            if (playerscoreint >= 20) {
                                sf::Text win;
                                win.setFont(font);
                                win.setString("BOT  WIN!"); // Set the string to display
                                win.setCharacterSize(50); // Set the text size (in pixels)
                                win.setFillColor(sf::Color::Red); // Set the text color
                                win.setPosition(250, 275);
                                window.clear();
                                window.draw(win);
                                window.draw(button);
                                window.draw(buttonText);
                                window.draw(playerscore);
                                window.draw(botscore);
                                window.draw(hvalue);

                                for (int i = 0; i < player1.playerdeck.size(); i++) {
                                    window.draw(player1.playerdeck[i].img);
                                    // std::cout << player1.playerdeck.size();
                                }
                                for (int i = 0; i < bot1.botdeck.size(); i++) {
                                    sf::Sprite tempBackview = bot1.botdeck[i].img; // Create a temporary copy
                                    tempBackview.setPosition((i + 1) * 100.f, 0.f);
                                    window.draw(tempBackview);
                                }
                                window.draw(player1.backview);

                                for (int i = 0; i < bot1.botthrowncard.size(); i++) {
                                    bot1.botthrowncard[i].img.setPosition(1000.f - 100.f * (i + 3), 250.f);
                                    window.draw(bot1.botthrowncard[i].img);
                                } {
                                    sf::Text exit;
                                    exit.setFont(font);
                                    exit.setString("press x to exit"); // Set the string to display
                                    exit.setCharacterSize(20); // Set the text size (in pixels)
                                    exit.setFillColor(sf::Color::Red); // Set the text color
                                    exit.setPosition(810, 20);
                                    window.draw(exit);

                                    sf::Text restart;
                                    restart.setFont(font);
                                    restart.setString("press r to restart"); // Set the string to display
                                    restart.setCharacterSize(20); // Set the text size (in pixels)
                                    restart.setFillColor(sf::Color::Red); // Set the text color
                                    restart.setPosition(810, 50);
                                    window.draw(restart);
                                    window.display();

                                    bool waitingForInput = true;

                                    while (waitingForInput) {
                                        while (window.pollEvent(event)) {
                                            if (event.type == sf::Event::Closed) {
                                                window.close();
                                                waitingForInput = false; // Exit the loop
                                            }
                                            if (event.type == sf::Event::KeyPressed) {
                                                if (event.key.code == sf::Keyboard::X) {
                                                    window.close(); // Close window when X is pressed
                                                    waitingForInput = false;
                                                }
                                                if (event.key.code == sf::Keyboard::R) {
                                                    window.close(); // Close window when R is pressed
                                                    goto target; // Jump to target label
                                                }
                                            }
                                        }
                                    }
                                }
                            } else if (botscoreint >= 20) {
                                sf::Text win;
                                win.setFont(font);
                                win.setString("PLAYER  WIN!"); // Set the string to display
                                win.setCharacterSize(50); // Set the text size (in pixels)
                                win.setFillColor(sf::Color::Red); // Set the text color
                                win.setPosition(250, 275);
                                window.clear();
                                window.draw(win);
                                window.draw(button);
                                window.draw(buttonText);
                                window.draw(playerscore);
                                window.draw(botscore);
                                window.draw(hvalue);

                                for (int i = 0; i < player1.playerdeck.size(); i++) {
                                    window.draw(player1.playerdeck[i].img);
                                    // std::cout << player1.playerdeck.size();
                                }
                                for (int i = 0; i < bot1.botdeck.size(); i++) {
                                    sf::Sprite tempBackview = bot1.botdeck[i].img; // Create a temporary copy
                                    tempBackview.setPosition((i + 1) * 100.f, 0.f);
                                    window.draw(tempBackview);
                                }
                                window.draw(player1.backview);

                                for (int i = 0; i < bot1.botthrowncard.size(); i++) {
                                    bot1.botthrowncard[i].img.setPosition(1000.f - 100.f * (i + 3), 250.f);
                                    window.draw(bot1.botthrowncard[i].img);
                                } {
                                    sf::Text exit;
                                    exit.setFont(font);
                                    exit.setString("press x to exit"); // Set the string to display
                                    exit.setCharacterSize(20); // Set the text size (in pixels)
                                    exit.setFillColor(sf::Color::Red); // Set the text color
                                    exit.setPosition(810, 20);
                                    window.draw(exit);

                                    sf::Text restart;
                                    restart.setFont(font);
                                    restart.setString("press r to restart"); // Set the string to display
                                    restart.setCharacterSize(20); // Set the text size (in pixels)
                                    restart.setFillColor(sf::Color::Red); // Set the text color
                                    restart.setPosition(810, 50);
                                    window.draw(restart);
                                    window.display();

                                    bool waitingForInput = true;

                                    while (waitingForInput) {
                                        while (window.pollEvent(event)) {
                                            if (event.type == sf::Event::Closed) {
                                                window.close();
                                                waitingForInput = false; // Exit the loop
                                            }
                                            if (event.type == sf::Event::KeyPressed) {
                                                if (event.key.code == sf::Keyboard::X) {
                                                    window.close(); // Close window when X is pressed
                                                    waitingForInput = false;
                                                }
                                                if (event.key.code == sf::Keyboard::R) {
                                                    window.close(); // Close window when R is pressed
                                                    goto target; // Jump to target label
                                                }
                                            }
                                        }
                                    }
                                }
                            } else {
                                goto label;
                            }
                        }
                    }
                }
            }
            window.clear();
            window.draw(button);
            window.draw(buttonText);
            window.draw(playerscore);
            window.draw(botscore);
            window.draw(hvalue);


            for (int i = 0; i < player1.playerdeck.size(); i++) {
                window.draw(player1.playerdeck[i].img);
                // std::cout << player1.playerdeck.size();
            }
            for (int i = 0; i < bot1.botdeck.size(); i++) {
                bot1.backview.setPosition((i + 1) * 100.f, 0.f);
                window.draw(bot1.backview);
            }
            window.draw(player1.backview);

            for (int i = 0; i < bot1.botthrowncard.size(); i++) {
                bot1.botthrowncard[i].img.setPosition(1000.f - 100.f * (i + 3), 250.f);
                window.draw(bot1.botthrowncard[i].img);
            }
        } else {
            window.clear();
            window.draw(button);
            window.draw(buttonText);
            window.draw(playerscore);
            window.draw(botscore);
            window.draw(hvalue);


            for (int i = 0; i < player1.playerdeck.size(); i++) {
                player1.playerdeck[i].img.setPosition((i + 1) * 100.f, 520.f);
                window.draw(player1.playerdeck[i].img);
            }
            for (int i = 0; i < bot1.botdeck.size(); i++) {
                bot1.backview.setPosition((i + 1) * 100.f, 0.f);
                window.draw(bot1.backview);
            }
            for (int i = 0; i < player1.throwncard.size(); i++) {
                player1.throwncard[i].img.setPosition(1000.f - 100.f * (i + 3), 250.f);
                window.draw(player1.throwncard[i].img);
            }
            window.draw(player1.backview);
            window.display();

            if (bot1.handvalue() <= 7) {
                window.clear();

                bot1.jhyap(player1, playerscoreint, botscoreint);
                playerscore.setString(std::to_string(playerscoreint)); // Set the string to display
                botscore.setString(std::to_string(botscoreint)); // Set the string to display
                window.draw(playerscore);
                window.draw(botscore);
                window.draw(button);
                window.draw(hvalue);
                window.draw(buttonText);


                for (int i = 0; i < player1.playerdeck.size(); i++) {
                    player1.playerdeck[i].img.setPosition((i + 1) * 100.f, 520.f);
                    window.draw(player1.playerdeck[i].img);
                }

                for (int i = 0; i < player1.throwncard.size(); i++) {
                    player1.throwncard[i].img.setPosition(1000.f - 100.f * (i + 3), 250.f);
                    window.draw(player1.throwncard[i].img);
                }
                window.draw(player1.backview);
                for (int i = 0; i < bot1.botdeck.size(); i++) {
                    sf::Sprite tempBackview = bot1.botdeck[i].img; // Create a temporary copy
                    tempBackview.setPosition((i + 1) * 100.f, 0.f);
                    window.draw(tempBackview);
                }
                sf::Text jhyaap;
                jhyaap.setFont(font);
                jhyaap.setString("BOT  CALLED  JHYAAP"); // Set the string to display
                jhyaap.setCharacterSize(25); // Set the text size (in pixels)
                jhyaap.setFillColor(sf::Color::Red); // Set the text color
                jhyaap.setPosition(250, 275);
                window.draw(jhyaap); {
                    bool waitingForC = true;

                    sf::Text con;
                    con.setFont(font);
                    con.setString("press c to continue"); // Set the string to display
                    con.setCharacterSize(20); // Set the text size (in pixels)
                    con.setFillColor(sf::Color::Red); // Set the text color
                    con.setPosition(810, 20);
                    window.draw(con);
                    window.display();

                    while (waitingForC) {
                        while (window.pollEvent(event)) {
                            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::C) {
                                waitingForC = false; // Exit the loop when 'C' is pressed
                            } if (event.type == sf::Event::Closed) {
                                window.close();
                                waitingForC = false; // Exit the loop
                            }
                        }
                    }

                    if (botscoreint >= 20) {
                        window.clear();
                        window.draw(playerscore);
                        window.draw(botscore);
                        window.draw(hvalue);
                        window.draw(button);
                        window.draw(buttonText);


                        for (int i = 0; i < player1.playerdeck.size(); i++) {
                            player1.playerdeck[i].img.setPosition((i + 1) * 100.f, 520.f);
                            window.draw(player1.playerdeck[i].img);
                        }

                        for (int i = 0; i < player1.throwncard.size(); i++) {
                            player1.throwncard[i].img.setPosition(1000.f - 100.f * (i + 3), 250.f);
                            window.draw(player1.throwncard[i].img);
                        }
                        window.draw(player1.backview);
                        for (int i = 0; i < bot1.botdeck.size(); i++) {
                            sf::Sprite tempBackview = bot1.botdeck[i].img; // Create a temporary copy
                            tempBackview.setPosition((i + 1) * 100.f, 0.f);
                            window.draw(tempBackview);
                        }

                        sf::Text win;
                        win.setFont(font);
                        win.setString("PLAYER  WIN!"); // Set the string to display
                        win.setCharacterSize(50); // Set the text size (in pixels)
                        win.setFillColor(sf::Color::Red); // Set the text color
                        win.setPosition(250, 275);
                        window.draw(win); {
                            sf::Text exit;
                            exit.setFont(font);
                            exit.setString("press x to exit"); // Set the string to display
                            exit.setCharacterSize(20); // Set the text size (in pixels)
                            exit.setFillColor(sf::Color::Red); // Set the text color
                            exit.setPosition(810, 20);
                            window.draw(exit);

                            sf::Text restart;
                            restart.setFont(font);
                            restart.setString("press r to restart"); // Set the string to display
                            restart.setCharacterSize(20); // Set the text size (in pixels)
                            restart.setFillColor(sf::Color::Red); // Set the text color
                            restart.setPosition(810, 50);
                            window.draw(restart);
                            window.display();

                            bool waitingForInput = true;
                            while (waitingForInput) {
                                while (window.pollEvent(event)) {
                                    if (event.type == sf::Event::Closed) {
                                        window.close();
                                        waitingForInput = false; // Exit the loop
                                    }
                                    if (event.type == sf::Event::KeyPressed) {
                                        if (event.key.code == sf::Keyboard::X) {
                                            window.close(); // Close window when X is pressed
                                            waitingForInput = false;
                                        }
                                        if (event.key.code == sf::Keyboard::R) {
                                            window.close(); // Close window when R is pressed
                                            goto target; // Jump to target label
                                        }
                                    }
                                }
                            }
                        }
                    } else if (playerscoreint >= 20) {
                        window.clear();
                        window.draw(playerscore);
                        window.draw(botscore);
                        window.draw(button);
                        window.draw(buttonText);
                        window.draw(hvalue);


                        for (int i = 0; i < player1.playerdeck.size(); i++) {
                            player1.playerdeck[i].img.setPosition((i + 1) * 100.f, 520.f);
                            window.draw(player1.playerdeck[i].img);
                            //std::cout << player1.playerdeck.size();
                        }

                        for (int i = 0; i < player1.throwncard.size(); i++) {
                            player1.throwncard[i].img.setPosition(1000.f - 100.f * (i + 3), 250.f);
                            window.draw(player1.throwncard[i].img);
                        }
                        window.draw(player1.backview);
                        for (int i = 0; i < bot1.botdeck.size(); i++) {
                            sf::Sprite tempBackview = bot1.botdeck[i].img; // Create a temporary copy
                            tempBackview.setPosition((i + 1) * 100.f, 0.f);
                            window.draw(tempBackview);
                        }
                        sf::Text win;
                        win.setFont(font);
                        win.setString("BOT  WIN!"); // Set the string to display
                        win.setCharacterSize(50); // Set the text size (in pixels)
                        win.setFillColor(sf::Color::Red); // Set the text color
                        win.setPosition(250, 275);
                        window.draw(win); {
                            sf::Text exit;
                            exit.setFont(font);
                            exit.setString("press x to exit"); // Set the string to display
                            exit.setCharacterSize(20); // Set the text size (in pixels)
                            exit.setFillColor(sf::Color::Red); // Set the text color
                            exit.setPosition(810, 20);
                            window.draw(exit);
                            sf::Text restart;
                            restart.setFont(font);
                            restart.setString("press r to restart"); // Set the string to display
                            restart.setCharacterSize(20); // Set the text size (in pixels)
                            restart.setFillColor(sf::Color::Red); // Set the text color
                            restart.setPosition(810, 50);
                            window.draw(restart);
                            window.display();

                            bool waitingForInput = true;

                            while (waitingForInput) {
                                while (window.pollEvent(event)) {
                                    if (event.type == sf::Event::Closed) {
                                        window.close();
                                        waitingForInput = false; // Exit the loop
                                    }
                                    if (event.type == sf::Event::KeyPressed) {
                                        if (event.key.code == sf::Keyboard::X) {
                                            window.close(); // Close window when X is pressed
                                            waitingForInput = false;
                                        }
                                        if (event.key.code == sf::Keyboard::R) {
                                            window.close(); // Close window when R is pressed
                                            goto target; // Jump to target label
                                        }
                                    }
                                }
                            }
                        }
                    } else {
                        goto label;
                    }
                }
            }
            bot1.botthrow();
            playerturn = true;
            bot1.botdeck.push_back(bot1.selectCardFromThrownOrDeck(player1.throwncard, deck));
            bot1.arrange();
        }
        window.display();
    }
    return 0;
}
