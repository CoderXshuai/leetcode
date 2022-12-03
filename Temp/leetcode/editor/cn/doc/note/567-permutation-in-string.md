基础滑动窗口框架方法

```c++
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

//runtime:16 ms
//memory:7.2 MB

```