# mycpp_progress

# 🧩 Gobang (Five in a Row Game)

This is my **first functional C++ project**, created to record my learning progress and practice fundamental programming skills.
It’s a **console-based Gomoku (Five in a Row)** game that allows two players to take turns placing stones on a 19×19 board until one wins.

---

## 🎮 Overview

This small project demonstrates basic concepts of procedural programming in C++.
It implements a fully playable two-player Gomoku game with simple terminal interaction.

Through this project, I practiced:

* Basic control flow in C++
* Array and coordinate mapping
* Modular function design
* Command-line input/output handling

---

## 📂 Project Structure

```
gobang.cpp      # Main program (contains all logic)
README.md       # Project documentation
```

---

## ⚙️ How to Run

### 1️⃣ Compile

Use any C++ compiler (e.g., g++, clang++, or Visual Studio):

```bash
g++ gobang.cpp -o gobang
```

### 2️⃣ Execute

```bash
./gobang
```

or on Windows:

```bash
gobang.exe
```

---

## 🕹️ How to Play

1. Launch the program, and you’ll see the main menu:

   ```
   1. Start Game
   2. Settings
   3. Exit
   ```
2. Choose **1** to start the game.
3. The system initializes a 19×19 chessboard and displays coordinates.
4. Players take turns to enter coordinates for their moves, for example:

   ```
   Enter move coordinates:
   10 10
   ```
5. If five stones of the same color connect in a row (horizontally, vertically, or diagonally), the system declares a winner and returns to the main menu.

---

## 🧠 Functional Design

| Module         | Function               | Description                             |
| -------------- | ---------------------- | --------------------------------------- |
| Initialization | `init()`               | Initializes the board and turn counter  |
| Game Flow      | `gameView()`           | Controls the main gameplay loop         |
| Board Display  | `gameView_ShowBoard()` | Prints the board in the console         |
| Move Handling  | `playerMove()`         | Validates and records a move            |
| Win Check      | `isWin()`              | Determines whether a player has won     |
| Win Screen     | `winView()`            | Displays the winner and returns to menu |
| Main Menu      | `menuView()`           | Provides entry point and exit options   |

---

## 🧩 Design Concepts

* **Board Representation:**
  `int board[20][20]` represents the 19×19 board.

  * `0`: empty
  * `1`: black stone
  * `2`: white stone

* **Victory Detection:**
  The program checks in four directions (horizontal, vertical, diagonal, and anti-diagonal) for five consecutive stones.

* **Turn Management:**
  The `flag` variable indicates turns:

  * even = black
  * odd = white

* **Input Validation:**
  Ensures that moves are within the board and not on an occupied cell.

---

## 👨‍💻 Author

* **Author:** Yucheng Zhu (朱玉成)
* **Language:** C++
* **Environment:** Visual Studio 2022 / g++
* **Project Type:** Personal practice project (first functional program)

---

## 🚀 Future Improvements

* [ ] Add AI (computer opponent) mode
* [ ] Add save/load feature
* [ ] Improve console interface appearance
* [ ] Implement a GUI version using EasyX or SFML

---

## 📜 License

This project is for **learning and educational purposes** only.
You are free to copy, modify, and extend it — please retain the author’s credit.


