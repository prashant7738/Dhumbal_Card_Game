🎴 Dhumbaal Card Game<br>
Welcome to the Dhumbaal Card Game! This is a digital version of the traditional card game implemented in C++ using SFML (Simple and Fast Multimedia Library).<br><br>
✨ Features<br>
•	🎮 Interactive Gameplay: Play against a bot in turn-based mode.<br>
•	🖱️ Dynamic Card Selection: Select cards with the mouse to create valid sets.<br>
•	📜 Game Rules Compliance: Ensures that only valid card combinations are accepted.<br>
•	🖼️ Smooth Visuals: Clean and interactive graphics rendered using SFML.<br>
•	🤖 AI Opponent: A bot that makes logical moves based on its cards.<br><br>
📜 Game Rules<br>
The objective of the game is to form valid sets of cards and strategically manage your hand to win.<br>
✅ Valid Card Sets:<br>
1. Same Value:<br>
   - All selected cards must have the same value (e.g., 3 of ♥️, 3 of ♠️, 3 of ♦️).<br>
2. Consecutive Sequence:<br>
   - Cards must form a consecutive sequence and have the same suit (e.g., 5, 6, 7 of ♠️).<br>
🔄 Gameplay Flow:<br>
1. Players take turns.<br>
2. On their turn, a player can:<br>
   - 📥 Pick a card from the deck or thrown card pile.<br>
   - 🃏 Select and throw a valid set of cards into the thrown deck.<br>
3. The bot automatically plays after the player’s turn.<br>
🛠️ Installation<br><br>
Prerequisites:<br>
•	🖥️ C++ Compiler: Ensure your compiler supports C++17 or higher.<br>
•	📦 SFML Library: Download and install SFML (version 2.5.1 or later).<br><br>
Steps:<br>
1.	Clone this repository:<br>
   git clone(https://github.com/bikesh19/Dhumbaal-game)<br>
   cd dhumbaal-card-game<br>
2.	Compile the code:<br>
   g++ -o dhumbaal main.cpp -lsfml-graphics -lsfml-window -lsfml-system<br>
3.	Run the executable:<br>
   ./dhumbaal<br><br>
🎮 Controls<br>
•	🖱️ Mouse Left Click: Select or deselect cards from your hand.<br>
•	⌨️ Keyboard: Use specific keys for menu navigation.<br>
📂 Project Structure<br>
/<br>
├── assets/               # Contains images and resources for the game<br>
├── src/                  # Source code files<br>
│   ├── main.cpp          # Main game logic<br>
│   ├── game.cpp          # Core game mechanics<br>
│   ├── bot.cpp           # Bot logic implementation<br>
│   └── player.cpp        # Player actions and interactions<br>
├── include/              # Header files<br>
└── README.md             # This file<br><br>

🚀 Future Improvements<br>
•	🌐 Add multiplayer support.<br>
•	🧠 Enhance AI strategy for the bot.<br>
•	🎨 Include animations for smoother gameplay experience.<br>
•	📡 Develop an online mode.<br>
