class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        sort(nums.begin(), nums.end());
        int diff_from_target = INT_MAX;
        int n = nums.size();
        int sum;
        int min_sum = INT_MAX;

        for (int fixed = 0; fixed < n - 2; fixed++) {
            if (fixed > 0 && nums[fixed] == nums[fixed - 1]) {
                continue;
            }

            int left = fixed + 1;
            int right = n - 1;

            while (left < right) {
                sum = nums[fixed] + nums[left] + nums[right];
                int diff = abs(sum - target);

                if (diff < diff_from_target) {
                    diff_from_target = diff;
                    min_sum = sum;
                }

                if (sum - target < 0) {
                    left++;
                }

                else if (sum - target > 0) {
                    right--;
                }

                else if (diff_from_target == 0) {
                    break;
                }
            }
        }

        return min_sum;
    }
};