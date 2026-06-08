class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector <int> shuffle;
        int forw = 0;
        int back = n;

        while (back < 2*n)
        {
            shuffle.push_back(nums[forw++]);
            shuffle.push_back(nums[back++]);
        }
        return shuffle;
    }
};