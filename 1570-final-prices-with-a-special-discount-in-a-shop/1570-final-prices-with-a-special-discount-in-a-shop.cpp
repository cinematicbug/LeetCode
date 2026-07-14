class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> st;
        int n = prices.size();
        vector<int> ans(n);
        st.push(0);

        for (int i = 1; i < n; i++) {
            while (!st.empty() && prices[st.top()] >= prices[i]) {
                int res = prices[st.top()] - prices[i];
                ans[st.top()] = res;
                st.pop();
            }
            st.push(i);
        }

        while (!st.empty()) {
            ans[st.top()] = prices[st.top()];
            st.pop();
        }

        return ans;
    }
};