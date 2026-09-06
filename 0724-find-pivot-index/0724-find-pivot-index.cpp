class Solution {
public:
    int pivotIndex(vector<int>& nums) {

        int n = nums.size();
        int arr[n];
        arr[0] = nums[0];

        for (int i = 1; i < n; i++) {
            arr[i] = nums[i] + arr[i - 1];
        }

        int left_arr[n];
        left_arr[0] = 0;

        for (int i = 1; i < n; i++) {
            left_arr[i] = arr[i - 1];
        }

        for (int i = 0; i < n; i++) {
            if (arr[n - 1] - arr[i] == left_arr[i]) {
                return i;
            }
        }

        return -1;
    }
};