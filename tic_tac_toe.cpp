#include <iostream>
#include <vector>

const int SIZE = 3;
char board[SIZE][SIZE];
char currentPlayer = 'X';

// Function to initialize or reset the board
void initializeBoard() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            board[i][j] = '1' + i * SIZE + j;  // 1-9 numbers for the grid
        }
    }
}

// Function to display the board
void displayBoard() {
    std::cout << "\n";
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            std::cout << " " << board[i][j] << " ";
            if (j < SIZE - 1) std::cout << "|";
        }
        std::cout << "\n";
        if (i < SIZE - 1) std::cout << "---+---+---\n";
    }
    std::cout << "\n";
}

// Function to check if a position is valid and available
bool isValidMove(int position) {
    int row = (position - 1) / SIZE;
    int col = (position - 1) % SIZE;
    return (position >= 1 && position <= 9 && board[row][col] != 'X' && board[row][col] != 'O');
}

// Function to update the board with the player's move
void updateBoard(int position) {
    int row = (position - 1) / SIZE;
    int col = (position - 1) % SIZE;
    board[row][col] = currentPlayer;
}

// Function to check for a win
bool checkWin() {
    // Check rows and columns
    for (int i = 0; i < SIZE; ++i) {
        if ((board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) ||
            (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)) {
            return true;
        }
    }
    // Check diagonals
    if ((board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) ||
        (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)) {
        return true;
    }
    return false;
}

// Function to check for a draw
bool checkDraw() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false;
            }
        }
    }
    return true;
}

// Function to switch players
void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

// Function to handle the game loop
void playGame() {
    int position;
    bool gameWon = false;
    initializeBoard();

    while (true) {
        displayBoard();
        std::cout << "Player " << currentPlayer << ", enter your move (1-9): ";
        std::cin >> position;

        if (isValidMove(position)) {
            updateBoard(position);

            if (checkWin()) {
                displayBoard();
                std::cout << "Player " << currentPlayer << " wins!\n";
                gameWon = true;
                break;
            } else if (checkDraw()) {
                displayBoard();
                std::cout << "The game is a draw!\n";
                break;
            }
            switchPlayer();
        } else {
            std::cout << "Invalid move. Please try again.\n";
        }
    }

    // Ask to play again
    char playAgain;
    std::cout << "Do you want to play again? (y/n): ";
    std::cin >> playAgain;
    if (playAgain == 'y' || playAgain == 'Y') {
        currentPlayer = 'X';  // Reset to 'X' for a new game
        playGame();
    } else {
        std::cout << "Thank you for playing Tic-Tac-Toe!\n";
    }
}

int main() {
    playGame();
    return 0;
}
