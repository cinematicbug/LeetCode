class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_map <int, int> freq;
        vector <int> sol;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (freq.contains(nums[i]))
            {
                sol.push_back(nums[i]);
                continue;
            }
            
            freq[nums[i]] = 0;
        }
        return sol;
    }
};