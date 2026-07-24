class Solution {
public:
    bool backspaceCompare(string s, string t) {

        int a = s.size() - 1;
        int b = t.size() - 1;

        int hash_a = 0;
        int hash_b = 0;

        while (a >= 0 || b >= 0) {
            while (a >= 0) {
                if (s[a] == '#') {
                    hash_a++;
                    a--;
                }

                else if (s[a] != '#' && hash_a > 0) {
                    hash_a--;
                    a--;
                }

                else {
                    break;
                }
            }

            while (b >= 0) {
                if (t[b] == '#') {
                    hash_b++;
                    b--;
                }

                else if (t[b] != '#' && hash_b > 0) {
                    hash_b--;
                    b--;
                }

                else {
                    break;
                }
            }

            if ((a >= 0) != (b >= 0)) {
                return false;
            }

            else if ((a >= 0) && (b >= 0)) {
                if (s[a] != t[b]) {
                    return false;
                }
            }
            a--;
            b--;
        }
        return true;
    }
};