class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {

        if (edges.size() != n - 1)
            return false;

        vector<vector<int>> adj(n);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> vis(n, 0);

        queue<pair<int,int>> q;
        q.push({0,-1});
        vis[0] = 1;

        int count = 1;

        while (!q.empty()) {

            auto [node,parent] = q.front();
            q.pop();

            for (auto nei : adj[node]) {

                if (!vis[nei]) {
                    vis[nei] = 1;
                    count++;
                    q.push({nei,node});
                }
                else if (nei != parent) {
                    return false;
                }
            }
        }

        return count == n;
    }
};