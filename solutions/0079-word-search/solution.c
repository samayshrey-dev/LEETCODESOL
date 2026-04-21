#include <stdio.h>

int dfs(char** board, int m, int n, int i, int j, char* word, int index) {
    // all characters matched
    if(word[index] == '\0') return 1;

    // boundary + mismatch check
    if(i < 0 || j < 0 || i >= m || j >= n || board[i][j] != word[index])
        return 0;

    char temp = board[i][j];
    board[i][j] = '#'; // mark visited

    // explore 4 directions
    int found = dfs(board, m, n, i+1, j, word, index+1) ||
                dfs(board, m, n, i-1, j, word, index+1) ||
                dfs(board, m, n, i, j+1, word, index+1) ||
                dfs(board, m, n, i, j-1, word, index+1);

    board[i][j] = temp; // backtrack

    return found;
}

int exist(char** board, int boardSize, int* boardColSize, char* word) {
    int m = boardSize;
    int n = boardColSize[0];

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(dfs(board, m, n, i, j, word, 0)) {
                return 1;
            }
        }
    }

    return 0;
}
