#include <iostream>
#include <vector>
#include <string>

using namespace std;

void getBoard(const vector<vector<char>>& board, const int& size_y, const int& size_x);
vector<vector<char>> ask(vector<vector<char>> &board, const string& player, const char& symbol, const int& size_x, const int& size_y, int& row, int& column);
bool
check(const vector<vector<char>> &board, const string &p1, const string &p2, int row, int column, const int &size_x,
      const int &size_y);

int main() {

    int size_x, size_y;
    string p1,p2;

    cout << "Enter the size of the board in the following format: \"column row\"" << endl;
    cin >> size_x;
    cin >> size_y;

    size_x--;
    size_y--;

    cout << "Player 1, enter your name:" << endl;
    cin >> p1;

    cout << "Player 2, enter your name:" << endl;
    cin >> p2;

    vector<vector<char>> board(size_y, vector<char>(size_x, '#'));

    cout << "Current board:" << endl;
    getBoard(board, size_y, size_x);

    int row, column;

    do {

        ask(board, p1, 'X', size_y, size_x, row, column);
        getBoard(board, size_y, size_x);

        if(check(board, p1, p2, row, column, size_x, size_y)){
            return EXIT_SUCCESS;
        }

        ask(board, p2, 'O', size_y, size_x, row, column);
        getBoard(board, size_y, size_x);

    } while (!check(board, p1, p2, row, column, size_x, size_y));

    return EXIT_SUCCESS;
}

vector<vector<char>> ask(vector<vector<char>> &board, const string& player, const char& symbol, const int& size_x, const int& size_y, int& row, int& column) {
    cout << player << " (x), Where would you like to place? (Enter column and row):" << endl;

    cin >> column;
    cin >> row;
    if (column < 1 or row < 1 or column > size_y or row > size_x){
        cout << "Ha ha nice try, you can't segfault me" << endl; // one of my last fixes, my mental health had degraded too much at this point
    }
    if (board[--row][--column] != '#'){
        cout << player << " tried to overwrite a sector.";
        ask(board, player, symbol, size_y, size_x, row, column);
    }

    board[row][column] = symbol; // line 57 already decreases it. Optimisation 1000 /s
    cout << "Current board:" << endl;

    return board;
}

bool check(const vector<vector<char>> &board, const string &p1, const string &p2, int row, int column, const int &size_x, const int &size_y) {
        // segfault catcher
    if ((row > size_y-3) && (column > size_x-3)){
        // be warned about it
    }

    if (row > size_y-3){

    }
    if (column > size_x-3){

    }

    // normal check
    int tempvar = 0;
    if(

            board[row][column]
            ){ //

    }
}

void getBoard(const vector<vector<char>>& board, const int& size_y, const int& size_x) { // prints the whole board
    for (int i = 0; i < size_y; ++i) {
        for (int j = 0; j < size_x; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}