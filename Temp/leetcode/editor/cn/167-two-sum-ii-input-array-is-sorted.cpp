#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;
        while (true) {
            int sum = numbers[left] + numbers[right];
            if (sum == target)
                return vector<int>{left + 1, right + 1};
            else if (sum > target)
                right--;
            else if (sum < target)
                left++;
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main() {
    Solution s;
}