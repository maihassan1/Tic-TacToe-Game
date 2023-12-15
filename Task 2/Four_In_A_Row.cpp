#include<iostream>
#include<random>
#include<iomanip>
#include<algorithm>
#include"BoardGame.h"
using namespace std;
Player::Player(char symbol) {
    this->symbol = symbol;
}
Player::Player (int order, char symbol) {
    cout << "Welcome player " << order << endl;
    cout << "Please enter your name: ";
    cin >> name;
    this->symbol = symbol;
}
void Player::get_move ( int& y) {
    cout << "\nPlease enter your move y (0 to 6) separated by spaces: ";
    cin >> y ;
}
string Player::to_string(){
    return "Player: " + name ;
}
char Player::get_symbol() {
    return symbol;
}
RandomPlayer::RandomPlayer (char symbol, int dimension):Player(symbol)
{
    this->dimension = dimension;
    this->name = "Random Computer Player";
    cout << "My names is " << name << endl;
}
void RandomPlayer::get_move ( int& y) {
    y = (int) (rand()/(RAND_MAX + 1.0) * 7);
}
GameManager::GameManager(Board* bPtr, Player* playerPtr[2] ) {
    boardPtr = bPtr;
    players[0] = playerPtr[0];
    players[1] = playerPtr[1];
}
void GameManager::run() {
    int x, y;
    boardPtr->display_board();
    while (!boardPtr->game_is_over()) {
        for (int i:{0,1}) {
            players[i]->get_move(y);
            while (!boardPtr->update_board( y, players[i]->get_symbol(), i)){
                players[i]->get_move(y);
            }
            boardPtr->display_board();
            if (boardPtr->is_winner()){
                cout  << players[i]->to_string() << " wins\n";
                return;
            }
            if (boardPtr->is_draw()){
                cout << "Draw!\n";
                return;
            }
        }
    }
}
Four_in_a_row_Board::Four_in_a_row_Board() : Board() {
    n_rows = 6;
    n_cols = 7;
    board = new char*[n_rows];
    for (int i = 0; i < n_rows; ++i) {
        board[i] = new char[n_cols];
        for (int j = 0; j < n_cols; ++j) {
            board[i][j] = ' ';
        }
    }
}
bool Four_in_a_row_Board::update_board(int column, char symbol, char i) {
    // Check if the column is within the valid range
    if (column < 0 || column >= n_cols) {
        cout << "Invalid column. Please choose a column between 0 and 6.\n";
        return false;
    }

    // Check if the column is full
    if (board[0][column] != ' ') {
        cout << "Column is full. Choose another column.\n";
        return false;
    }

    // Find the lowest empty square in the chosen column and place the symbol
    for (int row = n_rows - 1; row >= 0; --row) {
        if (board[row][column] == ' ') {
            board[row][column] = symbol;
            n_moves++;
            return true;
        }
    }

    return false; // This should not be reached, but added for completeness
}


void Four_in_a_row_Board::display_board() {
    cout << "  1   2   3   4   5   6   7" << endl;
    cout << "-----------------------------" << endl;
    for (int i = 0; i < n_rows; ++i) {
        for (int j = 0; j < n_cols; ++j) {
            cout << "| " << board[i][j] << " ";
        }
        cout << "|" << endl;
        cout << "-----------------------------" << endl;
    }
}

bool Four_in_a_row_Board::is_winner() {
    // Check for a win condition (vertical, horizontal, or diagonal)
    for (int i = 0; i < n_rows; ++i) {
        for (int j = 0; j < n_cols; ++j) {
            char currentSymbol = board[i][j];

            // Check horizontally
            if (j + 3 < n_cols &&
                currentSymbol != ' ' &&
                currentSymbol == board[i][j + 1] &&
                currentSymbol == board[i][j + 2] &&
                currentSymbol == board[i][j + 3]) {
                return true;
            }

            // Check vertically
            if (i + 3 < n_rows &&
                currentSymbol != ' ' &&
                currentSymbol == board[i + 1][j] &&
                currentSymbol == board[i + 2][j] &&
                currentSymbol == board[i + 3][j]) {
                return true;
            }

            // Check diagonally (top-left to bottom-right)
            if (i + 3 < n_rows && j + 3 < n_cols &&
                currentSymbol != ' ' &&
                currentSymbol == board[i + 1][j + 1] &&
                currentSymbol == board[i + 2][j + 2] &&
                currentSymbol == board[i + 3][j + 3]) {
                return true;
            }

            // Check diagonally (bottom-left to top-right)
            if (i - 3 >= 0 && j + 3 < n_cols &&
                currentSymbol != ' ' &&
                currentSymbol == board[i - 1][j + 1] &&
                currentSymbol == board[i - 2][j + 2] &&
                currentSymbol == board[i - 3][j + 3]) {
                return true;
            }
        }
    }

    return false;
}

bool Four_in_a_row_Board::is_draw() {
    // Check if the board is full, indicating a draw
    return n_moves == n_rows * n_cols;
}

bool Four_in_a_row_Board::game_is_over() {
    return is_winner() || is_draw();
}
int main() {
    int choice;
    Player* players[2];
    players[0] = new Player (1, 'x');

    cout << "Welcome to FCAI Four In A Row Game. :)\n";
    cout << "Press 1 if you want to play with computer: ";
    cin >> choice;
    if (choice != 1)
        players[1] = new Player (2, 'o');
    else
        //Player pointer points to child
        players[1] = new RandomPlayer ('o', 3);

    GameManager x_o_game (new Four_in_a_row_Board(), players);
    x_o_game.run();
    system ("pause");
}
