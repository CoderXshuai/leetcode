#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    void moveZeroes(vector<int> &nums) {
        int fast = 0;
        int slow = 0;
        while (fast < nums.size()) {
            while (fast < nums.size() && nums[slow] == 0 && nums[fast] == 0)
                fast++;
            if (fast >= nums.size())
                return;
            if (nums[slow] == 0) {
                swap(nums[slow], nums[fast]);
            }
            slow++;
            fast++;
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main() {
    Solution s = Solution();
    int arr[] = {0, 1, 0, 3, 12};
    vector<int> v(arr, arr + sizeof(arr) / sizeof(int));
    s.moveZeroes(v);
}