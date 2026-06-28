class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int sum = 0;
        for (int i = 0; i < words.size(); i++)
        {
            bool val = true;
            for (char j : words[i])
            {
                if (allowed.find(j) == allowed.npos)
                {
                    val = false;
                    break;
                }
            }
            if (val)
            {
                sum++;
            }
        }
        return sum;
    }
};