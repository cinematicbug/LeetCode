class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        if ((right + 1) == 1 || nums[left] > nums[left + 1]) {
            return 0;
        }

        if (nums[right] > nums[right - 1]) {
            return right;
        }

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] > nums[mid + 1] && nums[mid] > nums[mid - 1]) {
                return mid;
            }

            else if (nums[mid] < nums[mid + 1]) {
                left = mid + 1;
            }

            else {
                right = mid - 1;
            }
        }

        return 0;
    }
};