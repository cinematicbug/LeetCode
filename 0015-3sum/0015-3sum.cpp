class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector <vector<int>> ans;
        sort(nums.begin(), nums.end());
        int left;
        int right;
        int sum = 0;
        for (int fixed = 0; fixed < (int)nums.size() - 2; fixed++)
        {
            if (fixed > 0 && nums[fixed] == nums[fixed - 1])
            {
                continue;
            }
            left = fixed + 1;
            right = nums.size() - 1;
            while (left < right)
            {
                sum = nums[left] + nums[right];

                if (sum == -nums[fixed])
                {
                    ans.push_back({nums[fixed], nums[left], nums[right]});
                    left++;
                    while (left < right && nums[left] == nums[left - 1])
                    {
                        left++;
                    }
                    right--;
                    while (left < right && nums[right] == nums[right + 1])
                    {
                        right--;
                    }
                }

                else if (sum > -nums[fixed])
                {
                    right--;
                }

                else if (sum < -nums[fixed])
                {
                    left++;
                }

            }
        }
        return ans;
    }
};