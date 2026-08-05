class Solution {
public:
    int firstUniqChar(string s) {

        unordered_map<char, int> freq;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (freq.contains(s[i])) {
                freq[s[i]]++;
            } else {
                freq[s[i]] = 1;
            }
        }

        for (int i = 0; i < n; i++) {
            if (freq[s[i]] == 1) {
                return i;
            }
        }

        return -1;
    }
};