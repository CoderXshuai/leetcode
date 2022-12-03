#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> window;
        unordered_map<char, int> need;
        int m_size = s.size() + 1;
        int start = 0;
        int valid = 0;
        for (const auto &item: t)
            need[item]++;
        int left = 0;
        int right = 0;
        while (right < s.size()) {
            char c = s[right];
            right++;
            if (need.count(c)) {
                window[c]++;
                if (need[c] == window[c])
                    valid++;
            }
            while (valid == need.size()) {
                char d = s[left];
                if (need.count(d)) {
                    if (need[d] == window[d]) {
                        valid--;
                        if (right - left < m_size) {
                            m_size = right - left;
                            start = left;
                        }
                    }
                    window[d]--;
                }
                left++;
            }
        }
        return m_size < s.size() + 1 ? s.substr(start, m_size) : "";
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main() {
    Solution solution;
    string s = "abc";
    string t = "b";
    cout << solution.minWindow(s, t);
}