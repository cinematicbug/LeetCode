class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int x = g.size();
        int y = s.size();

        int i = 0;
        int j = 0;
        int count = 0;

        while (i < x && j < y) {
            while (j < y && g[i] > s[j]) {
                j++;
            }

            if (j < y && i < x && g[i] <= s[j]) {
                count++;
                i++;
                j++;
            }
        }

        return count;
    }
};