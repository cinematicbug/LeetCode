class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());

        int n = people.size();
        int left = 0;
        int right = n - 1;
        int boat_counter = 0;

        while (left <= right) {
            if (people[left] + people[right] > limit) {
                right--;
            }

            else {
                left++;
                right--;
            }
            boat_counter++;
        }

        return boat_counter;
    }
};