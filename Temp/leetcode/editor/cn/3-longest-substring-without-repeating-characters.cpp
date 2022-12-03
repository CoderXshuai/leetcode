#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> window;
        int left = 0;
        int right = 0;
        int len = 0;
        int res = 0;
        //dvdf不行。坚定区间为[left,right-1)
        while (right < s.size()) {
            char c = s[right];
            right++;
            window[c]++;
            while (window[c] > 1) {
                char d = s[left];
                left++;
                if (right - left > len) {
                    len = right - left;
                }
                window[d]--;
            }
        }
        return max(right - left, len);
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main() {
    Solution s;
    string s1 = "abcabcbb";
    cout << s.lengthOfLongestSubstring(s1);
}