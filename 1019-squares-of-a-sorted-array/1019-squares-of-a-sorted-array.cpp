class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {

        int n = nums.size();

        for (int& x : nums) {
            x = x * x;
        }

        vector<int> aux(n);

        int l = 0;
        int r = n - 1;
        int i = n - 1;

        while (l < r) {

            if (nums[r] > nums[l]) {
                aux[i--] = nums[r--];
                // cout << "i: " << i << ", r: " << r << "\n";
            }

            else {
                aux[i--] = nums[l++];
                // cout << "i: " << i << ", l: " << l << "\n";
            }
        }

        if (l == r) {
            aux[i] = nums[l];
            // cout << "i: " << i << ", r: " << r << "l: " << l << "\n";
        }

        return aux;
    }
};