class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> fsum;

        for (int fixed1 = 0; fixed1 < n - 3; fixed1++) {

            if (fixed1 > 0 && nums[fixed1] == nums[fixed1 - 1]) {
                continue;
            }
            for (int fixed2 = fixed1 + 1; fixed2 < n - 2; fixed2++) {
                int left = fixed2 + 1;
                int right = n - 1;

                if (fixed2 > fixed1 + 1 && nums[fixed2] == nums[fixed2 - 1]) {
                    continue;
                }
                while (left < right) {
                    long long sum = (long long)nums[fixed1] + nums[fixed2] +
                                    nums[left] + nums[right];

                    if (sum == target) {
                        vector<int> curr_sol;
                        curr_sol.push_back(nums[fixed1]);
                        curr_sol.push_back(nums[fixed2]);
                        curr_sol.push_back(nums[left]);
                        curr_sol.push_back(nums[right]);

                        fsum.push_back(curr_sol);
                        right--;
                        left++;

                        while (left < right && nums[left] == nums[left - 1]) {
                            left++;
                        }

                        while (left < right && nums[right] == nums[right + 1]) {
                            right--;
                        }
                    }

                    else if (sum > target) {
                        right--;
                    }

                    else {
                        left++;
                    }
                }
            }
        }
        return fsum;
    }
};