class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<vector<pair<int, int>>> adj(n);
        int sz = times.size();

        for (int i = 0; i < sz; i++) {
            adj[times[i][0] - 1].push_back({times[i][1] - 1, times[i][2]});
        }

        queue<pair<int, int>> q;
        int src = k - 1;
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        q.push({src, 0});

        while (!q.empty()) {
            int s = q.size();

            auto x = q.front();
            q.pop();

            for (auto& neighbours : adj[x.first]) {
                if ((dist[x.first] + neighbours.second) <
                    dist[neighbours.first]) {
                    dist[neighbours.first] = dist[x.first] + neighbours.second;
                    q.push({neighbours.first, dist[neighbours.first]});
                }
            }
        }

        if (count(dist.begin(), dist.end(), INT_MAX)) {
            return -1;
        }

        return *max_element(dist.begin(), dist.end());
    }
};