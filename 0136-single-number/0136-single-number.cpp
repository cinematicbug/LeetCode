class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> freq;

        for (int i = 0; i < nums.size(); i++) {
            if (freq.contains(nums[i])) {
                freq[nums[i]]++;
            } else {
                freq[nums[i]] = 1;
            }
        }

        for (const auto& pair : freq) {
            if (pair.second == 1) {
                return pair.first;
            }
        }
        return 0;
    }
};