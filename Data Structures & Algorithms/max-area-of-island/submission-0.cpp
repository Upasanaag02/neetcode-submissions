class Solution {
public:
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    void dfs(vector<vector<int>>& grid,int i,int j,vector<vector<int>>&vis,int &count){
          if(grid[i][j]==0 || vis[i][j]){return ;}
          vis[i][j]=1;
          count++;
          for(int k=0;k<4;k++){
            int nx=i+dx[k];
            int ny=j+dy[k];
            if(nx>=0 && ny>=0 && nx<grid.size()&& ny<grid[0].size()){
                 dfs(grid,nx,ny,vis,count);
            }
          }
          
    }

 
    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int maxval=0;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int count=0;
                if(!vis[i][j] && grid[i][j]==1){
                    dfs(grid,i,j,vis,count);
                }
                maxval=max(count,maxval);
            }
        }
        return maxval;
    }
};
