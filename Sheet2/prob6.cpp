#include <bits/stdc++.h>

using namespace std;

class Universe{
private:
    int grid[20][20];
public:
    void initialize();
    void reset();
    int count_neighbors( int r, int c);
    void next_generation();
    void display();
    void run();
};

void Universe:: reset(){
    for(int i = 0; i < 20; i++){
        for(int j = 0; j < 20; j++){
            grid[i][j]=0;
        }
    }
}

void Universe:: initialize(){
    int n;
    reset();
    cout<< "Enter integers from 1 to 400 to occupy cells, and enter -1 to start "<<endl;
        while (cin>> n){
            if(n == -1){
                break;
            }
            if(n >= 1 && n <= 400){
                int x = (n - 1) / 20; //row
                int y = (n - 1) % 20; //column
                grid[x][y] = 1;
            }
            else{
                cout<<"Invalid number. Try again "<<endl;
            }
        }
    }

int Universe:: count_neighbors(int r, int c){
    int count = 0;

    for(int i = r - 1; i <= r + 1; i++){
        for(int j = c - 1; j <= c + 1; j++){
            if ((i != r || j != c) && (i >= 0 && j >= 0) && (i < 20 && j < 20)){
                count += grid[i][j];
            }
        }
    }
    return count;
}


void Universe:: next_generation(){
    int new_grid[20][20] = {0};

    for(int i = 0; i < 20; i++){
        for(int j = 0; j < 20; j++){
            int live_cells=count_neighbors(i,j);
            if(grid[i][j] == 1){
                if(live_cells < 2 || live_cells > 3){
                    new_grid[i][j] = 0;
                } else{
                    new_grid[i][j] = 1;
                }
            }else {
                if(live_cells == 3){
                    new_grid[i][j] = 1;
            }
            }
    }
    }
    for (int i = 0; i < 20; i++){
        for(int j = 0; j < 20; j++){
            grid[i][j] = new_grid[i][j];
        }
    }
}

void Universe:: display(){
    system("cls");

    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            cout << grid[i][j] << "  ";
        }
        cout << endl;
    }
}

void Universe:: run(){

    initialize();
    int no_of_runs;
    cout<<"How many times would you like to run the game? (enter an integer): "<<endl;
    cin>> no_of_runs;
    for(int i = 0; i < no_of_runs; i++){
        display();
        next_generation();
    }

}

int main(){
    Universe gameoflife;
    gameoflife.run();

}
