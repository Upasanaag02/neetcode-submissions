class Solution {
public:
    bool dfs(string src,
             string dest,
             unordered_map<string, vector<pair<string,double>>> &adj,
             unordered_set<string> &vis,
             double product,
             double &ans)
    {
        if(src == dest){
            ans = product;
            return true;
        }

        vis.insert(src);

        for(auto &child : adj[src]){
            string next = child.first;
            double weight = child.second;

            if(vis.count(next))
                continue;

            if(dfs(next, dest, adj, vis, product * weight, ans))
                return true;
        }

        return false;
    }

    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {

        unordered_map<string, vector<pair<string,double>>> adj;

        // Build graph
        for(int i = 0; i < equations.size(); i++){
            string u = equations[i][0];
            string v = equations[i][1];
            double w = values[i];

            adj[u].push_back({v, w});
            adj[v].push_back({u, 1.0 / w});
        }

        vector<double> answer;

        for(auto &query : queries){

            string src = query[0];
            string dest = query[1];

            // Variable doesn't exist
            if(adj.find(src) == adj.end() || adj.find(dest) == adj.end()){
                answer.push_back(-1.0);
                continue;
            }

            unordered_set<string> vis;
            double ans = -1.0;

            dfs(src, dest, adj, vis, 1.0, ans);

            answer.push_back(ans);
        }

        return answer;
    }
};