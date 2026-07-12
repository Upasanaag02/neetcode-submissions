class Solution {
public:

    void dfs(vector<vector<char>>& grid,int i,int j,vector<vector<int>> &vis){
        if(grid[i][j]=='0'){
            return;
        }
        if(vis[i][j]==1){
            return;
        }
        else{
            vis[i][j]=1;
            if(i>0)dfs(grid,i-1,j,vis);
            if(j>0)dfs(grid,i,j-1,vis);
            if(j<grid[0].size()-1)dfs(grid,i,j+1,vis);
            if(i<grid.size()-1)dfs(grid,i+1,j,vis);
        }
    }


    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1' && vis[i][j]==0){
                    dfs(grid,i,j,vis);
                    count++;
                }
            }
        }
        return count;
    }
};
