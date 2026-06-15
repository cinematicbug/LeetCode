class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        vector <int> sol;
        for (int i : nums1)
        {
            auto ele = distance(nums2.begin(), find(nums2.begin(), nums2.end(), i));
            for (auto k = ele; k < nums2.size(); k++)
            {
                int max = -1;
                if (nums2[k] > nums2[ele])
                {
                    max = nums2[k];
                    sol.push_back(nums2[k]);
                    break;
                }

                else if (k == nums2.size() - 1 && max == -1)
                {
                    sol.push_back(-1);
                }
            }
        }
        return sol;
    }
};