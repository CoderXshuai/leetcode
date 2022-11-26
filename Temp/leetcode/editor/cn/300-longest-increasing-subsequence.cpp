#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        vector<int> dp(nums.size(), 1);
        for (int i = 0; i < nums.size(); ++i) {
            int max = INT_MIN;
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    max = std::max(max, dp[j] + 1);
                }
            }
            dp[i] = std::max(dp[i], max);
        }
        return *std::max_element(dp.begin(), dp.end());
    }

};
//leetcode submit region end(Prohibit modification and deletion)

int main() {
    Solution s = Solution();
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    s.lengthOfLIS(nums);
}