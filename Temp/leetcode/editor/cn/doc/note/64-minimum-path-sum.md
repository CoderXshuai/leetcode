my
问题出在没有对i和j为0的情况单独处理，所以耗时较长

```c++
class Solution {
public:
    int minPathSum(vector<vector<int>> &grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> dp(row, vector<int>(col, INT_MAX));
        dp[0][0] = grid[0][0];
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (i > 0)
                    dp[i][j] = dp[i - 1][j] + grid[i][j];
                if (j > 0)
                    dp[i][j] = min(dp[i][j], dp[i][j - 1] + grid[i][j]);
            }
        }
        return dp[row - 1][col - 1];
    }
};

//runtime:12 ms
//memory:9.9 MB
```

标准

```c++
class Solution {
public:
    int minPathSum(vector<vector<int>> &grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> dp(row, vector<int>(col, 100));
        dp[0][0] = grid[0][0];
        for (int i = 1; i < row; i++) {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }
        for (int j = 1; j < col; j++) {
            dp[0][j] = dp[0][j - 1] + grid[0][j];
        }
        for (int i = 1; i < row; ++i) {
            for (int j = 1; j < col; ++j) {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }
        return dp[row - 1][col - 1];
    }
};

//runtime:8 ms
//memory:9.8 MB
```