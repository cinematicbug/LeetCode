class Solution {
public:
    string addBinary(string a, string b) {
        int x = a.size() - 1;
        int y = b.size() - 1;
        int carry = 0;
        int sum = 0;
        string ans;

        while (x >= 0 && y >= 0) {
            sum = (a[x] - '0') + (b[y] - '0') + carry;

            if (sum == 0 || sum == 1) {
                carry = 0;
                ans.push_back(sum + '0');
            }

            else if (sum == 2) {
                carry = 1;
                ans.push_back('0');
            }

            else if (sum == 3) {
                carry = 1;
                ans.push_back('1');
            }

            x--;
            y--;
        }

        while (x >= 0) {
            sum = (a[x] - '0') + carry;
            if (sum == 0 || sum == 1) {
                carry = 0;
                ans.push_back(sum + '0');
            }

            else if (sum == 2) {
                carry = 1;
                ans.push_back('0');
            }

            else if (sum == 3) {
                carry = 1;
                ans.push_back('1');
            }

            x--;
        }

        while (y >= 0) {
            sum = (b[y] - '0') + carry;
            if (sum == 0 || sum == 1) {
                carry = 0;
                ans.push_back(sum + '0');
            }

            else if (sum == 2) {
                carry = 1;
                ans.push_back('0');
            }

            else if (sum == 3) {
                carry = 1;
                ans.push_back('1');
            }

            y--;
        }

        if (carry != 0) {
            ans.push_back('1');
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};