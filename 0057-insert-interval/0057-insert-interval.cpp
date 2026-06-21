class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        if (intervals.empty())
        {
            intervals.push_back(newInterval);
            return intervals;
        }
        auto it = lower_bound(intervals.begin(), intervals.end(), newInterval);
        vector <vector <int>> sol;

        intervals.insert(it, newInterval);
        sol.push_back(intervals[0]);

        for (int i = 0; i < intervals.size(); i++)
        {
            vector <int> curr = intervals[i];
            vector <int> &last = sol.back();

            if (last[1] >= curr[0])
            {
                last[1] = max(last[1], curr[1]);
                sol.back()[1] = last[1];
            }

            else
            {
                sol.push_back(curr);
            }
        }

        return sol;

    }
};