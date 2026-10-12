#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Ship.h"

using namespace std;

const int ROWS = 10;
const int COLS = 10;

void initializeBoard(char board[ROWS][COLS]) {
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            board[r][c] = '~';
        }
    }
}

void displayBoard(char board[ROWS][COLS]) {
    cout << "   0 1 2 3 4 5 6 7 8 9\n";
    for (int r = 0; r < ROWS; r++) {
        cout << r << " ";
        for (int c = 0; c < COLS; c++) {
            cout << board[r][c] << " ";
        }
        cout << endl;
    }
}

bool placeShipRandomly(char board[ROWS][COLS], const Ship& ship) {
    int size = ship.getSize();
    char symbol = ship.getSymbol();
    int direction = rand() % 2;
    int startRow, startCol = 0;

    if (direction == 0) {
        startRow = rand() % ROWS;
        startCol = rand() % (COLS - size + 1);

        for (int c = 0; c < size; c++) {
            if (board[startRow][startCol + c] != '~') return false;
        }

        for (int c = 0; c < size; c++) {
            board[startRow][startCol + c] = symbol;
        }
    } else {
        startRow = rand() % (ROWS - size + 1);
        startCol = rand() % COLS;

        for (int r = 0; r < size; r++) {
            if (board[startRow + r][startCol] != '~') return false;
        }

        for (int r = 0; r < size; r++) {
            board[startRow + r][startCol] = symbol;
        }
    }
    return true;
}

int main() {
    srand(static_cast<unsigned int>(time(0)));

    char board[ROWS][COLS];
    initializeBoard(board);

    vector<Ship> ships = {
        Ship("Frigate", 2, 'F'),
        Ship("Sub", 3, 'S'),
        Ship("Destroyer", 3, 'D'),
        Ship("Battleship", 4, 'B'),
        Ship("Aircraft Carrier", 5, 'A')
    };

    for (size_t i = 0; i < ships.size(); i++) {
        bool placed = false;
        while (!placed) {
            placed = placeShipRandomly(board, ships[i]);
        }
    }

    cout << "--- Battleship Game Board (Step 3) ---\n\n";
    displayBoard(board);

    int userRow, userCol;
    cout << "\n--- Take a Shot! ---" << endl;
    cout << "Enter row (0 to " << ROWS - 1 << "): ";
    cin >> userRow;
    cout << "Enter column (0 to " << COLS - 1 << "): ";
    cin >> userCol;
    
    if (userRow >= 0 && userRow < ROWS && userCol >= 0 && userCol < COLS) {
        if (board[userRow][userCol] != '~' && board[userRow][userCol] != 'X' && board[userRow][userCol] != 'O') {
            cout << "HIT!" << endl;
            board[userRow][userCol] = 'X';
        }
        else if (board[userRow][userCol] == '~') {
            cout << "MISS!" << endl;
            board[userRow][userCol] = 'O';
        }
        else {
            cout << "You already guessed that spot!" << endl;
        }
    } else {
        cout << "Invalid coordinates!" << endl;
    }

    cout << "\n--- updated Battleship Board ---" << endl;
    displayBoard(board);

    return 0;
}
            
