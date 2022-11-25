```c++
public:
    int removeElement(vector<int> &nums, int val) {
        int fast = 0;
        int slow = 0;
        while (fast != nums.size()) {
            if (nums[fast] != val) {
                if (fast != slow)
                    swap(nums[fast], nums[slow]);
                slow++;
            }
            fast++;
        }
        return slow;
    }
```