class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector <int> smaller;
        vector <int> greater;
        vector <int> eq;
        for (int i : nums)
        {
            if (i < pivot)
            {
                smaller.push_back(i);
            }
            else if (i > pivot)
            {
                greater.push_back(i);
            }
            else
            {
                eq.push_back(i);
            }
        }
        smaller.insert(smaller.end(), eq.begin(), eq.end());
        smaller.insert(smaller.end(), greater.begin(), greater.end());

        return smaller;
    }
};