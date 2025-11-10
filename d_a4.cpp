#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> board;
vector<int> colUsed, diag1Used, diag2Used;
int solutionCount = 0;

void printSolution() {
    cout << "\nSolution " << ++solutionCount << ":\n";
    for (auto &row : board) {
        for (int cell : row)
            cout << (cell ? "Q " : ". ");
        cout << endl;
    }
}

void solve(int row) {
    if (row == n) {
        printSolution();
        return; // Do NOT stop — continue to find more solutions
    }

    // If this row contains the fixed queen, skip placing
    for (int col = 0; col < n; col++) {
        if (board[row][col] == 1) {
            solve(row + 1);
            return;
        }
    }

    for (int col = 0; col < n; col++) {
        if (!colUsed[col] && !diag1Used[row - col + n - 1] && !diag2Used[row + col]) {

            board[row][col] = 1;
            colUsed[col] = diag1Used[row - col + n - 1] = diag2Used[row + col] = 1;

            solve(row + 1);

            // Backtrack
            board[row][col] = 0;
            colUsed[col] = diag1Used[row - col + n - 1] = diag2Used[row + col] = 0;
        }
    }
}

int main() {
    int r, c;
    cout << "Enter n: ";
    cin >> n;

    board.assign(n, vector<int>(n, 0));
    colUsed.assign(n, 0);
    diag1Used.assign(2 * n - 1, 0);
    diag2Used.assign(2 * n - 1, 0);

    cout << "Enter fixed queen position (row and column starting from 0): ";
    cin >> r >> c;

    // Place the fixed queen
    board[r][c] = 1;
    colUsed[c] = diag1Used[r - c + n - 1] = diag2Used[r + c] = 1;

    solve(0);

    if (solutionCount == 0)
        cout << "\nNo solutions exist for this placement.\n";
    else
        cout << "\nTotal solutions found: " << solutionCount << endl;

    return 0;
}
