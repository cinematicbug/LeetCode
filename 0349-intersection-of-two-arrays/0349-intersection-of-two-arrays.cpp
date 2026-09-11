class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int n = nums1.size();
        int m = nums2.size();
        vector<int> sol;

        int n1 = 0;
        int n2 = 0;

        while (n1 < n && n2 < m) {
            if (nums1[n1] == nums2[n2]) {
                if (find(sol.begin(), sol.end(), nums1[n1]) == sol.end()) {
                    sol.push_back(nums1[n1]);
                }

                n1++;
                n2++;
            }

            if (n1 < n && n2 < m && nums1[n1] > nums2[n2]) {
                n2++;
            }

            else if (n2 < m && n1 < n && nums1[n1] < nums2[n2]) {
                n1++;
            }
        }

        return sol;
    }
};