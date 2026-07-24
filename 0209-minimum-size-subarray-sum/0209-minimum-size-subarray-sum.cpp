class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int min_len = INT_MAX;
        int left = 0;
        int n = nums.size();
        int sum = 0;

        for (int right = 0; right < n; right++) {
            sum += nums[right];

            while (sum >= target) {
                sum -= nums[left];
                min_len = min(right - left + 1, min_len);
                left++;
            }
        }

        if (min_len == INT_MAX) {
            return 0;
        }

        return min_len;
    }
};