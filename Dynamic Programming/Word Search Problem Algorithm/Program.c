#include<bits/stdc++.h>
using namespace std;

bool searchNext(vector<vector<char>> &board, string word, int row, int col, int index, int m, int n) {
    if (index == word.length())
        return true;

    if (row < 0 || col < 0 || row == m || col == n || board[row][col] != word[index] || board[row][col] == '!')
        return false;

    char currentChar = board[row][col];
    board[row][col] = '!';

    bool top = searchNext(board, word, row - 1, col, index + 1, m, n);
    bool right = searchNext(board, word, row, col + 1, index + 1, m, n);
    bool bottom = searchNext(board, word, row + 1, col, index + 1, m, n);
    bool left = searchNext(board, word, row, col - 1, index + 1, m, n);

    board[row][col] = currentChar;

    return top || right || bottom || left;
}

bool exist(vector<vector<char>> &board, string word) {
    int m = board.size();
    int n = board[0].size();
    int index = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == word[index]) {
                if (searchNext(board, word, i, j, index, m, n))
                    return true;
            }
        }
    }

    return false;
}

int main() {
    vector<vector<char>> board = {{'A','B','C','E'},
                                  {'S','F','C','S'},
                                  {'A','D','E','E'}};

    string word = "ABCCED";

    bool result = exist(board, word);
    if (result)
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}
