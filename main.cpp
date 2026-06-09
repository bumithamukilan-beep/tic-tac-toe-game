#include <iostream>
#include <vector>
#include <limits>

using namespace std;

class TicTacToe {
private:
    vector<char> board;
    char currentPlayer;

public:
    TicTacToe() {
        board = {'1', '2', '3',
                 '4', '5', '6',
                 '7', '8', '9'};

        currentPlayer = 'X';
    }

    void displayBoard() {
        cout << "\n";
        cout << "     |     |     \n";
        cout << "  " << board[0] << "  |  " << board[1] << "  |  " << board[2] << "\n";
        cout << "_____|_____|_____\n";
        cout << "     |     |     \n";
        cout << "  " << board[3] << "  |  " << board[4] << "  |  " << board[5] << "\n";
        cout << "_____|_____|_____\n";
        cout << "     |     |     \n";
        cout << "  " << board[6] << "  |  " << board[7] << "  |  " << board[8] << "\n";
        cout << "     |     |     \n";
    }

    void switchPlayer() {
        if (currentPlayer == 'X') {
            currentPlayer = 'O';
        } else {
            currentPlayer = 'X';
        }
    }

    bool checkWinner() {

        if (board[0] == board[1] && board[1] == board[2])
            return true;

        if (board[3] == board[4] && board[4] == board[5])
            return true;

        if (board[6] == board[7] && board[7] == board[8])
            return true;

        if (board[0] == board[3] && board[3] == board[6])
            return true;

        if (board[1] == board[4] && board[4] == board[7])
            return true;

        if (board[2] == board[5] && board[5] == board[8])
            return true;

        if (board[0] == board[4] && board[4] == board[8])
            return true;

        if (board[2] == board[4] && board[4] == board[6])
            return true;

        return false;
    }

    bool checkDraw() {
        for (int i = 0; i < 9; i++) {
            if (board[i] != 'X' && board[i] != 'O') {
                return false;
            }
        }

        return true;
    }

    void makeMove() {
        int choice;

        while (true) {

            cout << "\nPlayer " << currentPlayer << ", enter position (1-9): ";
            cin >> choice;

            if (cin.fail()) {

                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << "Invalid input! Please enter a number.\n";
                continue;
            }

            if (choice < 1 || choice > 9) {

                cout << "Invalid position! Choose between 1 and 9.\n";
                continue;
            }

            if (board[choice - 1] == 'X' || board[choice - 1] == 'O') {

                cout << "Position already occupied! Try again.\n";
                continue;
            }

            board[choice - 1] = currentPlayer;
            break;
        }
    }

    void resetGame() {

        board = {'1', '2', '3',
                 '4', '5', '6',
                 '7', '8', '9'};

        currentPlayer = 'X';
    }

    void playGame() {

        char replayChoice;

        do {

            resetGame();

            bool gameOver = false;

            cout << "\n========== TIC TAC TOE ==========\n";
            cout << "Player X vs Player O\n";

            while (!gameOver) {

                displayBoard();

                makeMove();

                displayBoard();

                if (checkWinner()) {

                    cout << "\nPlayer " << currentPlayer << " Wins!\n";
                    gameOver = true;
                }

                else if (checkDraw()) {

                    cout << "\nGame Draw!\n";
                    gameOver = true;
                }

                else {

                    switchPlayer();
                }
            }

            cout << "\nDo you want to play again? (Y/N): ";
            cin >> replayChoice;

        } while (replayChoice == 'Y' || replayChoice == 'y');

        cout << "\nThank You for Playing!\n";
    }
};

int main() {

    TicTacToe game;

    game.playGame();

    return 0;
}
