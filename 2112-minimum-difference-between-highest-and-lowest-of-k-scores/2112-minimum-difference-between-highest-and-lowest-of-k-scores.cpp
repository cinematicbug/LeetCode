class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();

        if (n == 1) {
            return 0;
        }

        sort(nums.begin(), nums.end());
        int min = nums[k - 1] - nums[0];

        for (int i = 1; i <= n - k; i++) {
            if ((nums[k + i - 1] - nums[i]) < min) {
                min = nums[k + i - 1] - nums[i];
            }
        }

        return min;
    }
};