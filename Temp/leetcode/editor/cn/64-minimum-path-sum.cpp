#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
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
//leetcode submit region end(Prohibit modification and deletion)

int main() {
    Solution s = Solution();
}