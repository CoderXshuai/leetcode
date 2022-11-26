#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int max;

    int coinChange(vector<int> &coins, int amount) {
        max = amount + 1;
        vector<int> res(max, max);
        res[0] = 0;
        for (const auto &item: coins) {
            res[item] = 1;
        }
        int ans = dp(res, amount, coins);
        if (ans > amount)
            return -1;
        return ans;
    }

    int dp(vector<int> &res, int amount, vector<int> &coins) {
        int temp = max;
        if (amount < 0)
            return temp;
        if (res[amount] < max)
            return res[amount];
        for (const auto &item: coins) {
            temp = min(temp, dp(res, amount - item, coins) + 1);
        }
        res[amount] = temp;
        return res[amount];
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main() {
    Solution s = Solution();
    vector<int> coins(1, 2);
    int amount = 3;
    int ans = s.coinChange(coins, amount);
    cout << ans;
}