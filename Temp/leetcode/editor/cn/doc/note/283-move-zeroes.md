```c++
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
```

先删除，再补0

```c++
public:
    void moveZeroes(vector<int> &nums) {
        int fast = 0;
        int slow = 0;
        while (fast < nums.size()) {
            if (nums[fast] != 0) {
                nums[slow] = nums[fast];
                slow++;
            }
            fast++;
        }
        for (int i = 1; i <= nums.size() - slow; ++i) {
            nums[slow+i-1]=0;
        }
    }
```