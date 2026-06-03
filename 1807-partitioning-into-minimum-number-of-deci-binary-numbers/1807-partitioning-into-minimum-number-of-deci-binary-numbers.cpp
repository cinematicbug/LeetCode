class Solution {
public:
    int minPartitions(string n) {
        int max = -1;
        for (char i:n)
        {
            if ((i - '0') > max)
            {
                max = i - '0';
            }
        }
        return max;
    }
};