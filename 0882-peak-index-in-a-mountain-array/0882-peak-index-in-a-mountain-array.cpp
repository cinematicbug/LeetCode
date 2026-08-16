class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {

        int left = 0;
        int right = arr.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (mid > 0 &&
                (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])) {
                return mid;
            }

            else if (mid > 0 && arr[mid] < arr[mid - 1]) {
                right = mid - 1;
            } else if (mid < arr.size() - 1 && arr[mid] < arr[mid + 1]) {
                left = mid + 1;
            }

            if (mid == 0 && arr[mid + 1] > arr[mid]) {
                return mid + 1;
            }
        }
        return -1;
    }
};