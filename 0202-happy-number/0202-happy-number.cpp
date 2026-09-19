class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> st;
        int res = sum(n);

        while (!st.contains(res) && res != 1) {
            st.insert(res);
            res = sum(res);
        }

        return res == 1;
    }

    int sum(int n) {
        int sum_of_digits = 0;

        while (n > 0) {
            sum_of_digits += (n % 10) * (n % 10);
            n = n / 10;
            cout << sum_of_digits << " ";
        }

        return sum_of_digits;
    }
};