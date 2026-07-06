class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int max_ar = -1;
        while (left < right)
        {
            int width = right - left;
            int curr_arr = width * (min(height[left], height[right]));
            if (height[left] <= height[right])
            {
                left++;
            }
            else
            {
                right--;
            }
            if (curr_arr > max_ar)
            {
                max_ar = curr_arr;
            }
        }
        return max_ar;
    }
};