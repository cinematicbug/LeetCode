class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {

        vector<vector<pair<int, int>>> adj(n);

        for (int i = 0; i < flights.size(); i++) {
            adj[flights[i][0]].emplace_back(flights[i][1], flights[i][2]);
        }

        vector<int> dis(n, INT_MAX);
        dis[src] = 0;
        queue<pair<int, int>> q;
        q.push({src, 0});
        int stops = 0;

        while (!q.empty() && stops <= k) {
            int s = q.size();

            for (int i = 0; i < s; i++) {
                auto x = q.front();
                q.pop();

                for (auto& [neighbor, cost] : adj[x.first]) {
                    if (x.second + cost < dis[neighbor]) {
                        dis[neighbor] = x.second + cost;
                        q.push({neighbor, dis[neighbor]});
                    }
                }
            }

            stops++;
        }

        if (dis[dst] == INT_MAX) {
            return -1;
        }

        return dis[dst];
    }
};