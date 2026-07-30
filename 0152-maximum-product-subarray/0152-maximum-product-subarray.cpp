class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_prod = nums[0];
        int min_prod = nums[0];
        int res = nums[0];
        int n = nums.size();

        for (int i = 1; i < n; i++) {
            if (nums[i] < 0) {
                swap(min_prod, max_prod);
            }

            max_prod = max(max_prod * nums[i], nums[i]);
            min_prod = min(nums[i], min_prod * nums[i]);
            res = max(max_prod, res);
        }

        return res;
    }
};