class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {

        int n = nums.size();
        int prefix[n];
        prefix[0] = nums[0];

        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + nums[i];
        }

        int left[n];
        left[0] = 0;

        for (int i = 1; i < n; i++) {
            left[i] = prefix[i - 1];
        }

        int total = prefix[n - 1];

        for (int i = 0; i < n; i++) {
            if (left[i] == total - prefix[i]) {
                return i;
            }
        }

        return -1;
    }
};