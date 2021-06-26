#include <iostream>
#include <vector>
#include <string>

using namespace std;

void getBoard(const vector<vector<char>>& board, const int& size_x, const int& size_y);
vector<vector<char>> ask(vector<vector<char>> &board, const string& player, const char& symbol);
bool check(vector<vector<char>> board, const string& p1, const string& p2);

int main() {

    int size_x, size_y;
    string p1,p2;

    cout << "Enter the size of the board in the following format: \"column row\"" << endl;
    cin >> size_x;
    cin >> size_y;

    cout << "Player 1, enter your name:" << endl;
    cin >> p1;

    cout << "Player 2, enter your name:" << endl;
    cin >> p2;

    vector<vector<char>> board(size_y, vector<char>(size_x, '#'));

    cout << "Current board:" << endl;
    getBoard(board, size_y, size_x);

    do {
        ask(board, p1, 'X');

        cout << "Current board:" << endl;
        getBoard(board, size_y, size_x);


        if(check(board, p1, p2)){
            return EXIT_SUCCESS;
        }

        ask(board, p2, 'O');

        cout << "Current board:" << endl;
        getBoard(board, size_y, size_x);

    } while (!check(board, p1, p2));

    return EXIT_SUCCESS;
}

vector<vector<char>> ask(vector<vector<char>> &board, const string& player, const char& symbol) {
    int row, column;

    cout << player << " (x), Where would you like to place? (Enter column and row):" << endl;

    cin >> column;
    cin >> row;
    if (column < 1 or row < 1 or column > 3 or row > 3){
        cout << "Ha ha nice try, you can't segfault me" << endl; // one of my last fixes, my mental health had degraded too much at this point
    }
    if (board[--row][--column] != '#'){
        cout << player << " tried to overwrite a sector.";
        ask(board, player, symbol);
    }

    board[row][column] = symbol; // line 57 already decreases it. Optimisation 1000 /s

    return board;
}

bool check(vector<vector<char>> board, const string& p1, const string& p2) {
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == 'x' && board[i][1] == 'x' && board[i][2] == 'x') || (board[0][i] == 'x' && board[1][i] == 'x' && board[2][i] == 'x')) {
            cout << p1 << " wins!" << endl;
            return true;
        }

        else if ((board[i][0] == 'o' && board[i][1] == 'o' && board[i][2] == 'o') || (board[0][i] == 'o' && board[1][i] == 'o' && board[2][i] == 'o')) {
            cout << p2 << " wins!" << endl;
            return true;
        }
    }
    if ((board[0][0] == 'x' && board[1][1] == 'x' && board[2][2] == 'x') || (board[2][0] == 'x' && board[1][1] == 'x' && board[0][2] == 'x')){
        cout << p1 << " wins!" << endl;
        return true;
    }
    else if ((board[0][0] == 'o' && board[1][1] == 'o' && board[2][2] == 'o') || (board[2][0] == 'o' && board[1][1] == 'o' && board[0][2] == 'o')){
        cout << p2 << " wins!" << endl;
        return true;
    } // there should be a shorter way to do this, the line's so long it looks like java

    return false;
}

void getBoard(const vector<vector<char>>& board, const int& size_y, const int& size_x) { // prints the whole board
    for (int i = 0; i < size_y; ++i) {
        for (int j = 0; j < size_x; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}