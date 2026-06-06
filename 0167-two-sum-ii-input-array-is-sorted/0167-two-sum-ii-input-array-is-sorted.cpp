class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;
        int sum = 0;
        vector <int> ans;
        while (left < right)
        {
            sum = numbers[left] + numbers[right];
            
            if (sum < target)
            {
                left++;
            }

            else if (sum > target)
            {
                right--;
            }

            else
            {
                break;
            }
        }

        ans.push_back(++left);
        ans.push_back(++right);

        return ans;
    }
};