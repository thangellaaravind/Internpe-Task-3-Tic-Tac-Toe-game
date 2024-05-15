#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    cout << "heyy!! welcome to Tic Tac Toe!" << endl;

    vector<char> board(9, ' ');
    int currentPlayer = 1;
    while (true) {
        cout << "-------------" << endl;
        for (int i = 0; i < 3; ++i) {
            cout << "| " << board[i * 3] << " | " << board[i * 3 + 1] << " | " << board[i * 3 + 2] << " |" << endl;
            cout << "-------------" << endl;
        }

        int choice;
        cout << "Player " << currentPlayer << ", enter your move between (1-9): ";
        cin >> choice;

        
        if (choice < 1 || choice > 9 || board[choice - 1] != ' ') {
            cout << "Invalid input! Please enter a number between 1 and 9, and choose an empty cell." << endl;
            continue;
        }

        
        char symbol = (currentPlayer == 1) ? 'X' : 'O';
        board[choice - 1] = symbol;

        
        vector<vector<int>> winConditions = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8},
                                             {0, 3, 6}, {1, 4, 7}, {2, 5, 8},
                                             {0, 4, 8}, {2, 4, 6}};
        for (const auto &condition : winConditions) {
            if (all_of(condition.begin(), condition.end(), [&](int i) { return board[i] == symbol; })) {
                cout << "Congratulations!! Player " << currentPlayer << "You Won the Game!!" << endl;
                return 0;
            }
        }


        if (none_of(board.begin(), board.end(), [](char c) { return c == ' '; })) {
            cout << "Game draw!!" << endl;
            return 0;
        }

        
        currentPlayer = (currentPlayer == 1) ? 2 : 1;
    }

    return 0;
}
