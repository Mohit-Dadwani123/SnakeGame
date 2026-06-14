# Snake Game in C++

A simple console-based Snake Game implemented in C++ using object-oriented programming principles.

## Features

* Classic Snake gameplay
* Real-time keyboard controls (W, A, S, D)
* Random food generation
* Snake growth after eating food
* Score tracking
* Collision detection:

  * Wall collision
  * Self-collision
* Console-based rendering

## Requirements

* Windows Operating System
* C++ Compiler (GCC, MinGW, MSVC, etc.)
* Standard C++ Library

## Dependencies

The project uses the following headers:

```cpp
#include <iostream>
#include <deque>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
#include <ctime>
```

## Controls

| Key | Action     |
| --- | ---------- |
| W   | Move Up    |
| S   | Move Down  |
| A   | Move Left  |
| D   | Move Right |

## Game Rules

1. Control the snake using W, A, S, and D.
2. Eat the food (`*`) to gain points.
3. Each food item increases the score by 10 points.
4. The snake grows longer after eating food.
5. The game ends if:

   * The snake hits a wall.
   * The snake collides with itself.

## Compilation

Using g++:

```bash
g++ snake.cpp -o snake
```

## Running the Game

```bash
snake.exe
```

or

```bash
./snake
```

## Project Structure

```text
SnakeGame/
│
├── snake.cpp
├── README.md
└── snake_dataset.txt
```

## Sample Output

```text
######################
#                    #
#         O          #
#                *   #
#                    #
######################

Score: 0
Controls: W A S D
```

## Test Dataset

A sample test dataset file (`snake_test_dataset.txt`) can be used to validate:

* Movement logic
* Food consumption
* Score updates
* Wall collisions
* Self-collisions

## Future Improvements

* Pause and resume functionality
* Difficulty levels
* High score saving
* Colored console graphics
* Sound effects
* Cross-platform support (Linux/macOS)
* Menu system

## Author

Developed as a C++ console game project for learning data structures, game loops, and object-oriented programming concepts.

## License

This project is open-source and available under the MIT License.
