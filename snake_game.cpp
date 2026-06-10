#include <iostream>
#include <deque>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
#include <ctime>

using namespace std;

const int WIDTH = 20;
const int HEIGHT = 20;

struct Point {
    int x, y;

    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }
};

class SnakeGame {
private:
    deque<Point> snake;
    Point food;
    char direction;
    bool gameOver;
    int score;

public:
    SnakeGame() {
        snake.push_back({WIDTH / 2, HEIGHT / 2});
        direction = 'D';
        gameOver = false;
        score = 0;
        srand((unsigned)time(0));
        generateFood();
    }

    void generateFood() {
        while (true) {
            food.x = rand() % WIDTH;
            food.y = rand() % HEIGHT;

            bool onSnake = false;

            for (auto& segment : snake) {
                if (segment == food) {
                    onSnake = true;
                    break;
                }
            }

            if (!onSnake)
                break;
        }
    }

    void draw() {
        system("cls");

        for (int i = 0; i < WIDTH + 2; i++)
            cout << "#";
        cout << "\n";

        for (int y = 0; y < HEIGHT; y++) {
            cout << "#";

            for (int x = 0; x < WIDTH; x++) {
                Point current = {x, y};

                if (current == snake.front()) {
                    cout << "O"; // head
                }
                else if (current == food) {
                    cout << "*";
                }
                else {
                    bool body = false;

                    for (size_t i = 1; i < snake.size(); i++) {
                        if (snake[i] == current) {
                            body = true;
                            break;
                        }
                    }

                    cout << (body ? "o" : " ");
                }
            }

            cout << "#\n";
        }

        for (int i = 0; i < WIDTH + 2; i++)
            cout << "#";

        cout << "\nScore: " << score << endl;
        cout << "Controls: W A S D\n";
    }

    void input() {
        if (_kbhit()) {
            char key = toupper(_getch());

            switch (key) {
                case 'W':
                    if (direction != 'S') direction = 'W';
                    break;
                case 'S':
                    if (direction != 'W') direction = 'S';
                    break;
                case 'A':
                    if (direction != 'D') direction = 'A';
                    break;
                case 'D':
                    if (direction != 'A') direction = 'D';
                    break;
            }
        }
    }

    void update() {
        Point head = snake.front();

        switch (direction) {
            case 'W': head.y--; break;
            case 'S': head.y++; break;
            case 'A': head.x--; break;
            case 'D': head.x++; break;
        }

        // Wall collision
        if (head.x < 0 || head.x >= WIDTH ||
            head.y < 0 || head.y >= HEIGHT) {
            gameOver = true;
            return;
        }

        // Self collision
        for (auto& segment : snake) {
            if (head == segment) {
                gameOver = true;
                return;
            }
        }

        snake.push_front(head);

        if (head == food) {
            score += 10;
            generateFood();
        } else {
            snake.pop_back();
        }
    }

    void run() {
        while (!gameOver) {
            draw();
            input();
            update();

            Sleep(120);
        }

        cout << "\nGame Over!\n";
        cout << "Final Score: " << score << endl;
    }
};

int main() {
    SnakeGame game;
    game.run();
    return 0;
}