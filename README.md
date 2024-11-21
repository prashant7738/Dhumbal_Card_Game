🎴 Dhumbaal Card Game<br>
Welcome to the Dhumbaal Card Game! This is a digital version of the traditional card game implemented in C++ using SFML (Simple and Fast Multimedia Library).<br><br>
✨ Features<br>
•	🎮 Interactive Gameplay: Play against a bot in turn-based mode.<br>
•	🖱️ Dynamic Card Selection: Select cards with the mouse to create valid sets.
•	📜 Game Rules Compliance: Ensures that only valid card combinations are accepted.
•	🖼️ Smooth Visuals: Clean and interactive graphics rendered using SFML.
•	🤖 AI Opponent: A bot that makes logical moves based on its cards.
📜 Game Rules
The objective of the game is to form valid sets of cards and strategically manage your hand to win.
✅ Valid Card Sets:
1. Same Value:
   - All selected cards must have the same value (e.g., 3 of ♥️, 3 of ♠️, 3 of ♦️).
2. Consecutive Sequence:
   - Cards must form a consecutive sequence and have the same suit (e.g., 5, 6, 7 of ♠️).
🔄 Gameplay Flow:
1. Players take turns.
2. On their turn, a player can:
   - 📥 Pick a card from the deck or thrown card pile.
   - 🃏 Select and throw a valid set of cards into the thrown deck.
3. The bot automatically plays after the player’s turn.
🛠️ Installation
Prerequisites:
•	🖥️ C++ Compiler: Ensure your compiler supports C++17 or higher.
•	📦 SFML Library: Download and install SFML (version 2.5.1 or later).
Steps:
1.	Clone this repository:
   git clone https://github.com/yourusername/dhumbaal-card-game.git
   cd dhumbaal-card-game
2.	Compile the code:
   g++ -o dhumbaal main.cpp -lsfml-graphics -lsfml-window -lsfml-system
3.	Run the executable:
   ./dhumbaal
🎮 Controls
•	🖱️ Mouse Left Click: Select or deselect cards from your hand.
•	⌨️ Keyboard: Use specific keys for menu navigation (if applicable).
📂 Project Structure
/
├── assets/               # Contains images and resources for the game
├── src/                  # Source code files
│   ├── main.cpp          # Main game logic
│   ├── game.cpp          # Core game mechanics
│   ├── bot.cpp           # Bot logic implementation
│   └── player.cpp        # Player actions and interactions
├── include/              # Header files
└── README.md             # This file

🚀 Future Improvements
•	🌐 Add multiplayer support.
•	🧠 Enhance AI strategy for the bot.
•	🎨 Include animations for smoother gameplay experience.
•	📡 Develop an online mode.
