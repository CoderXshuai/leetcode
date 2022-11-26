#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    static bool compare(vector<int> &a, vector<int> &b) {
        if (a[0] == b[0])
            return a[1] < b[1];
        return a[0] < b[0];
    }

    int maxEnvelopes(vector<vector<int>> &envelopes) {
        int size = envelopes.size();
        vector<int> dp(size, 1);
        std::sort(envelopes.begin(), envelopes.end(), compare);
        for (int i = 0; i < size; ++i) {
            int m = INT_MIN;
            for (int j = 0; j < i; ++j) {
                if (envelopes[i][0] > envelopes[j][0] && envelopes[i][1] > envelopes[j][1])
                    m = max(m, dp[j] + 1);
            }
            dp[i] = max(dp[i], m);
        }
        return *std::max_element(dp.begin(), dp.end());
    }


};
//leetcode submit region end(Prohibit modification and deletion)

int main() {
    Solution s = Solution();
    vector<vector<int>> envelopes = {{4, 5},
                                     {4, 6},
                                     {6, 7},
                                     {2, 3},
                                     {1, 1}};
    s.maxEnvelopes(envelopes);
}