#include <stdio.h>

// DFS to sink island
void dfs(char** grid, int m, int n, int i, int j) {
    // boundary or water
    if(i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == '0')
        return;

    grid[i][j] = '0'; // mark visited

    dfs(grid, m, n, i+1, j); // down
    dfs(grid, m, n, i-1, j); // up
    dfs(grid, m, n, i, j+1); // right
    dfs(grid, m, n, i, j-1); // left
}

int numIslands(char** grid, int gridSize, int* gridColSize) {
    int m = gridSize;
    int n = gridColSize[0];
    int count = 0;

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] == '1') {
                count++;
                dfs(grid, m, n, i, j); // sink island
            }
        }
    }

    return count;
}
