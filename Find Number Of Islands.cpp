void dfs(int** arr, int row, int col, int n, int m) {
    if (row < 0 || row >= n || col < 0 || col >= m || arr[row][col] != 1) {
        return;
    }

    arr[row][col] = 0;

    dfs(arr, row - 1, col - 1, n, m);  // Up-left
    dfs(arr, row - 1, col, n, m);      // Up
    dfs(arr, row - 1, col + 1, n, m);  // Up-right
    dfs(arr, row, col - 1, n, m);      // Left
    dfs(arr, row, col + 1, n, m);      // Right
    dfs(arr, row + 1, col - 1, n, m);  // Down-left
    dfs(arr, row + 1, col, n, m);      // Down
    dfs(arr, row + 1, col + 1, n, m);  // Down-right
}

int getTotalIslands(int** arr, int n, int m) {
    int islandCount = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 1) {
                islandCount++;
                dfs(arr, i, j, n, m);
            }
        }
    }

    return islandCount;
}
