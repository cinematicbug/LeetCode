class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> ans;
        ans.reserve(nums.size());

        for (int x : nums) {
            if (ans.count(x)) {
                return true;
            }
            ans.insert(x);
        }

        return false;
    }
};