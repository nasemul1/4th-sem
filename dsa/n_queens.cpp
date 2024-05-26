#include <iostream>
#include <vector>
using namespace std;


// Function to check if a queen can be placed at the given position
bool isSafe(vector<vector<int>>& board, int row, int col, int N) {
    // Check if there is a queen in the same column
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1) {
            return false;
        }
    }


    // Check if there is a queen in the upper-left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }


    // Check if there is a queen in the upper-right diagonal
    for (int i = row, j = col; i >= 0 && j < N; i--, j++) {
        if (board[i][j] == 1) {
            return false;
        }
    }


    return true;
}


// Function to solve the N-Queens problem using backtracking
bool solveNQueensUtil(vector<vector<int>>& board, int row, int N) {
    if (row == N) {
        // All queens have been placed successfully
        return true;
    }


    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col, N)) {
            board[row][col] = 1;  // Place the queen


            // Recursively solve the problem for the next row
            if (solveNQueensUtil(board, row + 1, N)) {
                return true;
            }


            board[row][col] = 0;  // Backtrack and remove the queen
        }
    }


    return false;  // No solution found
}


// Function to solve the N-Queens problem and print the board
void solveNQueens(int N) {
    vector<vector<int>> board(N, vector<int>(N, 0));


    if (solveNQueensUtil(board, 0, N)) {
        // Solution found, print the board
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "No solution found for N = " << N << endl;
    }
}


int main() {
    int N;
    cout << "Enter the value of N: ";
    cin >> N;


    solveNQueens(N);


    return 0;
}
