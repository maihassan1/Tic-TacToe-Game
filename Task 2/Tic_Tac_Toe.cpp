#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
#include "../include/BoardGame_Classes.hpp"


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
if(n_moves==24)
    {
        // horizontal and vertical cells
    for (int i = 0; i < 5; i++)
    {
      for(int j = 0; j < 3; j++)
      {
        if (board[i][j] == board[i][j+1] && board[i][j+1] == board[i][j+2])
        {
            if (board[i][j] == 'X')
                x_count++;
            else if(board[i][j]== 'O')
              o_count++;
        }
        if (board[j][i] == board[j+1][i] && board[j+1][i] == board[j+2][i])
        {
            if (board[j][i] == 'X')
                x_count++;
            else if(board[j][i]== 'O')
                 o_count++;
        }
    }
    }
      //diagonal cells
    for (int i = 0;i < 3;i++)
    {
        for (int j = 0;j < 3;j++)
        {
            if (board[i + 2][j] == board[i + 1][i + 1] && board[i + 1][i + 1] == board[i][j + 2])
            {
                if (board[i + 2][j] == 'X')
                    x_count++;
                else if (board[i+2][j] == 'O')
                    o_count++;
            }
        }
    }
    for (int i = 0;i < 3;i++)
    {
        for (int j = 0;j < 3;j++)
        {
            if (board[i][j] == board[i + 1][i + 1] && board[i + 1][i + 1] == board[i+2][j + 2])
            {
                if (board[i][j] == 'X')
                    x_count++;
                else if(board[i][j] == 'X')
                    o_count++;
            }
        }
    }

   if (x_count > o_count){
        cout<<"Player X wins "<<endl;
        exit(0);
   }
    else if (o_count > x_count){
        cout<< "Player O wins "<<endl;
        exit(0);
    }

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
