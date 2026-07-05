class Solution {
public:
    int findGCD(vector<int>& nums) {
        int smallest = *min_element(nums.begin(), nums.end());
        int largest = *max_element(nums.begin(), nums.end());

        while (smallest != 0)
        {
            int rem = largest%smallest;
            largest = smallest;
            smallest = rem;
        }
        return largest;
    }
};