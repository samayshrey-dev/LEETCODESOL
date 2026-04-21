#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

// store results
char*** result;
int returnSize = 0;

// check if safe
int isSafe(int board[MAX][MAX], int row, int col, int n) {
    // check column
    for(int i = 0; i < row; i++) {
        if(board[i][col]) return 0;
    }

    // left diagonal
    for(int i = row-1, j = col-1; i >= 0 && j >= 0; i--, j--) {
        if(board[i][j]) return 0;
    }

    // right diagonal
    for(int i = row-1, j = col+1; i >= 0 && j < n; i--, j++) {
        if(board[i][j]) return 0;
    }

    return 1;
}

// save solution
void saveBoard(int board[MAX][MAX], int n) {
    result = realloc(result, (returnSize + 1) * sizeof(char**));
    result[returnSize] = malloc(n * sizeof(char*));

    for(int i = 0; i < n; i++) {
        result[returnSize][i] = malloc((n + 1) * sizeof(char));
        for(int j = 0; j < n; j++) {
            result[returnSize][i][j] = board[i][j] ? 'Q' : '.';
        }
        result[returnSize][i][n] = '\0';
    }

    returnSize++;
}

// backtracking
void solve(int board[MAX][MAX], int row, int n) {
    if(row == n) {
        saveBoard(board, n);
        return;
    }

    for(int col = 0; col < n; col++) {
        if(isSafe(board, row, col, n)) {
            board[row][col] = 1;

            solve(board, row + 1, n);

            board[row][col] = 0; // backtrack
        }
    }
}

// main function
char*** solveNQueens(int n, int* returnSizeOut, int** returnColumnSizes) {
    int board[MAX][MAX] = {0};
    result = NULL;
    returnSize = 0;

    solve(board, 0, n);

    *returnSizeOut = returnSize;

    // column sizes (all n)
    *returnColumnSizes = malloc(returnSize * sizeof(int));
    for(int i = 0; i < returnSize; i++) {
        (*returnColumnSizes)[i] = n;
    }

    return result;
}
