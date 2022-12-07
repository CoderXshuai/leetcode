#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string longestPalindrome(string s) {
        string res;
        for (int i = 0; i < s.size(); ++i) {
            string s1 = palindrome(s, i, i);
            string s2 = palindrome(s, i, i + 1);
            res = s1.size() > res.size() ? s1 : res;
            res = s2.size() > res.size() ? s2 : res;
        }
        return res;
    }

    string palindrome(string s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        return s.substr(left + 1, right - left - 1);
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main() {
    Solution s;
    string string1 = "babad";
    s.longestPalindrome(string1);
}