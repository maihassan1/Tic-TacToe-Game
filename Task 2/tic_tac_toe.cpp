#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
#include "../include/BoardGame_Classes.hpp"

class Tic_Tac_Toe :public Board {
public:
    Tic_Tac_Toe();
    bool update_board (int x, int y, char mark);
    void display_board();
    bool is_winner();
    bool is_draw();
    bool game_is_over();
};

class Tic_Tac_Toe_Player : public Player{
public:
    Tic_Tac_Toe_Player (char symbol);
    Tic_Tac_Toe_Player (int order, char symbol);
    void get_move(int& x, int& y);
    string to_string();
    char get_symbol();

};

class Tic_Tac_Toe_Rplayer: public RandomPlayer{
public:
    Tic_Tac_Toe_Rplayer (char symbol, int dimension);
    void get_move(int& x, int& y);
};

Tic_Tac_Toe ::Tic_Tac_Toe() {
    n_rows = n_cols = 5;
    board = new char*[n_rows]; //array of pointers
    for (int i = 0; i < n_rows; i++) {
        board [i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = 0;
    }
}

bool Tic_Tac_Toe::update_board (int x, int y, char mark){

    if (!(x < 0 || x > 4 || y < 0 || y > 4) && (board[x][y] == 0)) {
        board[x][y] = toupper(mark);
        n_moves++;
        return true;
    }
    else
        return false;
}


void Tic_Tac_Toe::display_board() {
     for (int i = 0; i < 5; i++) {
        cout << "\n| ";
        for (int j = 0; j < 5; j++) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << board [i][j] << " |";
        }
        cout << "\n------------------------------------------";
    }
    cout << endl;
}


bool Tic_Tac_Toe::is_winner() {
    int x_count = 0, o_count = 0;
if(n_moves==24){
    for (int i = 0; i < 5; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            if (board[i][0] == 'X') x_count++;
            else if (board[i][0] == 'O') o_count++;
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            if (board[0][i] == 'X') x_count++;
            else if (board[0][i] == 'O') o_count++;
        }
    }
    for(int i = 0;i < 3; i++){
        if (board[i][i]==board[i+1][i+1] && board[i+1][i+1]==board[i+2][i+2]){
           if (board[i][i] == 'X') x_count++;
           else if (board[i][i] == 'O') o_count++;
        }
        if (board[i+2][i] == board[i+1][i+1] && board[i+1][i+1] == board[i][i+2]){
           if (board[i+2][i] == 'X') x_count++;
           else if (board[i+2][i] == 'O') o_count++;
        }
    }
    for(int i=0; i<3; i++){
        if (board[i][4-i]==board[i+1][3-i] && board[i+1][3-i]==board[i+2][2-i]){
           if (board[i][4-i] == 'X') x_count++;
           else if (board[i][4-i] == 'O') o_count++;
        }
        if (board[i][i+2]==board[i+1][i+1] && board[i+1][i+1]==board[i+2][i]){
            if (board[i][i+2] == 'X') x_count++;
           else if (board[i][i+2] == 'O') o_count++;
        }

    }

   if (x_count > o_count){
        cout<<"player X wins "<<endl;

   }
    else if (o_count > x_count){
            cout<< "player O wins "<<endl;
    }

    exit(0);

}


return false;
}

bool Tic_Tac_Toe::is_draw() {
    return (n_moves == 24 && !is_winner());
}

bool Tic_Tac_Toe::game_is_over () {
    return n_moves >= 24;
}

Tic_Tac_Toe_Rplayer::Tic_Tac_Toe_Rplayer(char symbol,int dimension):RandomPlayer(symbol,dimension){
    this->dimension = dimension;
    this->name;
}

void Tic_Tac_Toe_Rplayer::get_move (int& x, int& y) {
    x = (int) (rand()/(RAND_MAX + 1.0) * dimension);
    y = (int) (rand()/(RAND_MAX + 1.0) *dimension);
}


Tic_Tac_Toe_Player::Tic_Tac_Toe_Player(char symbol):Player(symbol){
    this->symbol = symbol;

}

Tic_Tac_Toe_Player::Tic_Tac_Toe_Player(int order, char symbol): Player(order,symbol){

    this->symbol = symbol;

}

void Tic_Tac_Toe_Player::get_move(int& x, int& y){
    cout<<"\nPlease enter your move x and y (0 to 4) separated by spaces: ";
    cin>> x >> y;
}


char Tic_Tac_Toe_Player::get_symbol(){
    Player::get_symbol();

}
string Tic_Tac_Toe_Player:: to_string(){
    return "Player: " + name;

}
