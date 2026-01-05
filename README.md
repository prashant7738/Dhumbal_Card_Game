**🎴 Dhumbaal Card Game**

Welcome to the Dhumbaal Card Game! 
This is a high-performance digital version of the popular Nepali card game, featuring interactive graphics rendered using SFML.
Developed as a 2nd-semester project, it demonstrates Object-Oriented Programming (OOP) principles and basic AI implementation.

🤖 Features
Intelligent AI Opponent: A built-in bot that analyzes its hand and makes logical moves (discards high values/sets) to minimize its score.
Interactive Graphics: Smooth card selection and UI interactions powered by SFML.
Dynamic Gameplay: Real-time hand management and valid set detection.

📜 Game Rules
The objective is to minimize the total point value of the cards in your hand. If your total is 10 points or less, you can call for a "Show" (Jhyap).✅ Valid Card Sets (Meld)To reduce your points faster, you can throw multiple cards at once if they form:
Same Value (Set): Cards with the same rank (e.g., $3\heartsuit, 3\spadesuit, 3\diamondsuit$).Consecutive Sequence (Run): 
Three or more cards of the same suit in numerical order (e.g., $5\spadesuit, 6\spadesuit, 7\spadesuit$).🔄 Gameplay FlowDiscard:
On your turn, select a valid set or a single high-value card and throw it into the pile.Pick:
Draw a new card from the Face-down Deck or the Thrown Card Pile.Bot Turn:
The AI automatically calculates the best move after your turn ends.Victory:
If you call "Show" and have the lowest points, you win. If another player has fewer or equal points, you are "Busted" (Penalty).

🛠️ Installation & SetupPrerequisites
🖥️ C++ Compiler: Supports C++17 or higher.
📦 SFML Library: Version 2.5.1 or later.

StepsClone the repository:
Bashgit clone https://github.com/bikesh19/Dhumbaal-game
cd Dhumbaal-game
Compile the code:Bashg++ -o dhumbaal src/*.cpp -Iinclude -lsfml-graphics -lsfml-window -lsfml-system
Run the game:Bash./dhumbaal
🎮 Controls🖱️ Mouse Left Click: Select or deselect cards from your hand.⌨️ Keyboard: Use menu navigation keys (Enter/Esc) to interact with the game state.📂 Project StructurePlaintext/
├── assets/           # Textures, Fonts, and Sprites
├── include/          # Header files (.hpp/.h)
├── src/              # Source code implementation
│   ├── main.cpp      # Entry point
│   ├── game.cpp      # Game loop & State management
│   ├── bot.cpp       # AI logic & Decision making
│   └── player.cpp    # Hand management & Input handling
└── README.md
🚀 Future Improvements🌐 Multiplayer Support: LAN or Online socket-based gameplay.🧠 Advanced AI: Implement probability-based tracking of discarded cards.🎨 Visual Juice: Add card flip animations and particle effects.📡 Global Leaderboard: Track wins and scores online.
