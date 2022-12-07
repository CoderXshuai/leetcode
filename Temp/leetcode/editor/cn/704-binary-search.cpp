#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int search(vector<int> &nums, int target) {
        int left = 0;
        int right = nums.size();
        while (left < right) {
            int mid = (right - left) / 2 + left;
            if (nums[mid] == target)
                return mid;
            if (nums[mid] > target)
                right = mid;
            if (nums[mid] < target)
                left = mid + 1;
        }
        return -1;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main() {
    Solution s;
}