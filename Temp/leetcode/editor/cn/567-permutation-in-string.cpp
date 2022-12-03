#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> window;
        unordered_map<char, int> need;
        int left = 0;
        int right = 0;
        int valid = 0;
        for (const auto &item: s1)
            need[item]++;
        while (right < s2.size()) {
            char c = s2[right];
            right++;
            if (need.count(c)) {
                window[c]++;
                if (need[c] == window[c])
                    valid++;
            }
            while (valid == need.size()) {
                char d = s2[left];
                if (need.count(d)) {
                    if (need[d] == window[d]) {
                        if (right - left == s1.size())
                            return true;
                        valid--;
                    }
                    window[d]--;
                }
                left++;
            }
        }
        return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main() {
    Solution s;
    string s1 = "abcdxabcde";
    string s2 = "abcdeabcdx";
    s.checkInclusion(s1, s2);
}