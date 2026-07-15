class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int current_sum = 0;
        unordered_map<int, int> freq;
        freq[0] = 1;
        int count = 0;

        for (int num : nums) {
            current_sum += num;

            if (freq.contains(current_sum - k)) {
                count += freq[current_sum - k];
            }

            freq[current_sum]++;
        }

        return count;
    }
};