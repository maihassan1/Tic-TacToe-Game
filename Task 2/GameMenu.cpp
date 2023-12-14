#include <iostream>
#include <algorithm>
#include "C:\Users\مول الاصدقاء للاتسوق\CLionProjects\CS\BoardGame.h"
//#include "C:\Users\مول الاصدقاء للاتسوق\CLionProjects\CS\Pyramic_Board.cpp"
using namespace std;
void GameMenu::Menu(){
    int choice;

    cout << "1)X-O Game\n"
            "2)Pyramic Tic-Tac-Toe\n"
            "3) Four-in-a-row\n"
            "4)5 x 5 Tic Tac Toe\n"
            "choose from 1 to 4 : ";
    cin >>choice;


    if (choice == 1) {

        players[0] = new Player(1, 'x');
        cout << "choose 1 if you want computer player: ";
        cin >> choice;
        if (choice == 1) {
            players[1] = new RandomPlayer('o', 3);
        } else {
            players[1] = new Player('o');
        }
        GameManager x_o_game(new X_O_Board(), players);
        x_o_game.run();
    }
    if (choice == 2) {
        players[0] = new Player2('x',1);
        cout << "choose 1 if you want computer player: ";
        cin >> choice;
        if (choice == 1) {
            players[1] = new RandomPlayer('o', 5);
        } else {
            players[1] = new Player2('o',2);
        }
        GameManager x_o_game(new PyramicBoard(), players);
        x_o_game.run();
    }
    if (choice == 3) {

    }
    if (choice == 4) {
        Player* players[2];
    players[0] = new Tic_Tac_Toe_Player (1, 'x');
    cout << "choose 1 if you want computer player: ";
    cin >> choice;
    if (choice != 1)
        players[1] = new Tic_Tac_Toe_Player (2, 'o');
    else
        players[1] = new Tic_Tac_Toe_Rplayer ('o', 5);

    GameManager x_o_game (new Tic_Tac_Toe(), players);
    x_o_game.run();
    }
