#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int fast = 0;
        int slow = 0;
        while (fast < nums.size()) {
            if (nums[fast] != nums[slow]) {
                slow++;
                nums[slow] = nums[fast];
            }
            fast++;
        }
        return ++slow;
    }
};

//leetcode submit region end(Prohibit modification and deletion)
//int removeDuplicates(vector<int>& nums) {
//    int n = nums.size();
//    if (n == 0) {
//        return 0;
//    }
//    int fast = 1, slow = 1;
//    while (fast < n) {
//        if (nums[fast] != nums[fast - 1]) {
//            nums[slow] = nums[fast];
//            ++slow;
//        }
//        ++fast;
//    }
//    return slow;
//}
int main() {
    Solution s = Solution();
    int arr[] = {1, 1, 2};
//    auto v = vector<int>(arr, arr + sizeof(arr));
    vector<int> v(arr, arr + sizeof(arr) / sizeof(int));
    int a = s.removeDuplicates(v);
    cout << a;
}