class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<int>adj[n];
        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        queue<int>q;
        int count=0;
        vector<int>vis(n,0);

        for(int i=0;i<n;i++){
             for(auto it:adj[i]){
                vis[it]++;
             }
        }

        for(int i=0;i<n;i++){
             if(vis[i]==0){
                 q.push(i);
             }
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            count++;
            for(auto it:adj[node]){
                vis[it]--;
                if(vis[it]==0){q.push(it);}
            }
        }
        if(count==n){
            return true;
        }
        return false;
    }
};
