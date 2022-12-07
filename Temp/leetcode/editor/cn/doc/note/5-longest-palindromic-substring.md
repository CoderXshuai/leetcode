动态规划解法，设置`dp[n][m]`表示以`s[n]`开头以`s[m]`结尾的子串是否为回文串，然后进行斜着遍历

```c++
class Solution {
public:
    string longestPalindrome(string s) {
        int left = 0;
        int len = 0;
        int s_size = s.size();
        bool dp[s_size][s_size];
        for (int i = 0; i < s_size; ++i) {
            for (int j = 0; j < s_size - i; ++j) {
                int m = j;
                int n = i + j;
                if (s[m] == s[n]) {
                    if (i < 2)
                        dp[m][n] = true;
                    else
                        dp[m][n] = dp[m + 1][n - 1];
                    if (dp[m][n] && n - m + 1 > len) {
                        left = m;
                        len = n - m + 1;
                    }
                } else
                    dp[m][n] = false;
            }
        }
        return s.substr(left, len);
    }

};

//runtime:140 ms
//memory:7.8 MB
```

双指针解法，分别求出以`s[i]`和`s[i] s[i+1]`为中心的回文串

```c++
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
        return s.substr(left+1, right - left -1);
    }
};

//runtime:56 ms
//memory:164.7 MB

```
