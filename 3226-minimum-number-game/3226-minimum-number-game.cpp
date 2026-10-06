class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ptr = 0;

        while (ptr < n - 1) {
            swap(nums[ptr], nums[ptr + 1]);
            ptr += 2;
        }

        return nums;
    }
};