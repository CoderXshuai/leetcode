#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> window;
        unordered_map<char, int> need;
        int left = 0;
        int right = 0;
        int valid = 0;
        vector<int> res;
        for (const auto &item: p)
            need[item]++;
        while (right < s.size()) {
            char c = s[right];
            right++;
            if (need.count(c)) {
                window[c]++;
                if (window[c] == need[c])
                    valid++;
            }
            while (valid == need.size()) {
                char d = s[left];
                if (need.count(d)) {
                    if (window[d] == need[d]) {
                        if (right - left == p.size())
                            res.push_back(left);
                        valid--;
                    }
                    window[d]--;
                }
                left++;
            }
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main() {
    Solution s;
}