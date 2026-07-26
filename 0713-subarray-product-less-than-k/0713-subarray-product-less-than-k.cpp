class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {

        int product = 1;
        int count = 0;
        int left = 0;
        int n = nums.size();

        for (int right = 0; right < n; right++) {
            product *= nums[right];

            while (left <= right && product >= k) {
                product /= nums[left++];
            }

            count += right - left + 1;
        }

        return count;
    }
};