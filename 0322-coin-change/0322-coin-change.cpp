class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        vector<int> dp(amount + 1, -1);
        int res = result(coins, amount, dp);
        if (res == INT_MAX) {
            return -1;
        }

        return res;
    }

    int result(vector<int>& coins, int target, vector<int>& dp) {
        if (target == 0) {
            return 0;
        }

        if (target < 0) {
            return INT_MAX;
        }

        if (dp[target] != -1) {
            return dp[target];
        }

        int min_ = INT_MAX;
        for (int i = 0; i < coins.size(); i++) {
            int ans = result(coins, target - coins[i], dp);

            if (ans != INT_MAX) {
                min_ = min(min_, ans + 1);
            }
        }

        dp[target] = min_;
        return min_;
    }
};