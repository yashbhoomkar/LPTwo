#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void printBoard(vector<vector<char>> &board) {
        for (const auto& row : board) {
            for (char cell : row)
                cout << cell << " ";
            cout << endl;
        }
        cout << endl;
    }

    bool isSafe(vector<vector<char>> &board, int row, int col, int n) {
        // Check left side
        for (int i = 0; i < col; i++)
            if (board[row][i] == 'Q') return false;

        // Upper-left diagonal
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
            if (board[i][j] == 'Q') return false;

        // Lower-left diagonal
        for (int i = row, j = col; i < n && j >= 0; i++, j--)
            if (board[i][j] == 'Q') return false;

        return true;
    }

    void solve(vector<vector<char>> &board, int col, int n, vector<vector<vector<char>>> &solutions) {
        if (col == n) {
            solutions.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++) {
            if (isSafe(board, row, col, n)) {
                board[row][col] = 'Q';
                solve(board, col + 1, n, solutions);
                board[row][col] = '.';  // backtrack
            }
        }
    }

    void nQueens(int n) {
        vector<vector<char>> board(n, vector<char>(n, '.'));
        vector<vector<vector<char>>> solutions;

        solve(board, 0, n, solutions);

        cout << "Total solutions: " << solutions.size() << endl;
        for (auto &sol : solutions)
            printBoard(sol);
    }
};

int main() {
    Solution obj;
    int n = 5;
    obj.nQueens(n);
    return 0;
}
