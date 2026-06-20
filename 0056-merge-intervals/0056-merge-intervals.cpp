class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector <vector <int>> res;
        res.push_back(intervals[0]);
        int count = 0;

        for (int i = 1; i < intervals.size(); i++)
        {
            vector <int> &last = res.back();
            vector <int> curr = intervals[i];
            

            if (curr[0] <= last[1])
            {
                last[1] = max(curr[1], last[1]);
                res[count] = last;
            }

            else
            {
                res.push_back(curr);
                count++;
            }
        }
        return res;

    }
};