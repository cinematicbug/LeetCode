class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> ans;

        for (int x : nums) {
            if (ans.count(x)) {
                return true;
            }
            ans.insert(x);
        }

        return false;
    }
};