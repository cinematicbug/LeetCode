class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int s = (int)nums.size();

        double max_avg;
        double sum = 0;

        for (int i = 0; i < k; i++)
        {
            sum += (double)nums[i];
        }
        max_avg = sum/k;

        double new_s = sum;

        for (int i = k; i < s; i++)
        {
            new_s += (double)nums[i] - nums[i - k];
            if (new_s > sum)
            {
                sum = new_s;
            }
        }
        return sum/k;

    }
};