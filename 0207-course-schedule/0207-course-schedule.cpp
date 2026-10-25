class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        int n = prerequisites.size();
        vector<vector<int>> adj(numCourses);

        for (int i = 0; i < n; i++) {
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        vector<bool> isVisited(numCourses);
        vector<bool> isPath(numCourses);

        for (int i = 0; i < numCourses; i++) {
            if ((!isVisited[i]) && dfs(i, adj, isVisited, isPath))

            {
                return false;
            }
        }

        return true;
    }

    bool dfs(int i, vector<vector<int>>& adj, vector<bool>& isVisited,
             vector<bool>& isPath) {
        if (isPath[i]) {
            return true;
        }

        if (isVisited[i]) {
            return false;
        }

        isVisited[i] = true;
        isPath[i] = true;

        for (auto neighbour : adj[i]) {
            if (dfs(neighbour, adj, isVisited, isPath)) {
                return true;
            }
        }

        isPath[i] = false;
        return false;
    }
};