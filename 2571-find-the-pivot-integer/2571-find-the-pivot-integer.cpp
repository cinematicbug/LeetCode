class Solution {
public:
    int pivotInteger(int n) {
        int arr[n];

        for (int i = 1; i <= n; i++) {
            arr[i - 1] = i;
        }

        int prefix[n];
        prefix[0] = arr[0];

        for (int i = 1; i < n; i++) {
            prefix[i] = arr[i] + prefix[i - 1];
        }

        int left[n];
        left[0] = 0;

        for (int i = 1; i < n; i++) {
            left[i] = prefix[i - 1];
        }

        int total = prefix[n - 1];

        for (int i = 0; i < n; i++) {
            if (left[i] == (total - prefix[i])) {
                return i + 1;
            }
        }

        return -1;
    }
};