class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        int n = s.size();
        string rev = "";

        for (int i = 0; i < n; i++) {
            if (s[i] != '*') {
                st.push(s[i]);
            }

            else if (!st.empty() && s[i] == '*') {
                st.pop();
            }
        }

        while (!st.empty()) {
            rev += st.top();
            st.pop();
        }

        reverse(rev.begin(), rev.end());

        return rev;
    }
};