class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        queue<pair<int,int>>q;
        for(int j=0;j<m;j++){
             if(board[0][j]=='O'){
                q.push({0,j});
             }    
        }
        for(int j=0;j<n;j++){
             if(board[j][0]=='O'){
                q.push({j,0});
             }    
        }
        for(int j=0;j<m;j++){
             if(board[n-1][j]=='O'){
                q.push({n-1,j});
             }    
        }
        for(int j=0;j<n;j++){
             if(board[j][m-1]=='O'){
                q.push({j,m-1});
             }    
        }
        vector<vector<int>>vis(n,vector<int>(m,0));
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,-1,1};
        while(!q.empty()){
            auto[x,y]=q.front();
            q.pop();
            vis[x][y]=1;
            for(int k=0;k<4;k++){
                int nx=x+dx[k];
                int ny=y+dy[k];
                if(nx>=0 && ny>=0 && nx<n && ny<m && board[nx][ny]=='O' && vis[nx][ny]==0){
                    q.push({nx,ny});
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O' && vis[i][j]==0){
                    board[i][j]='X';
                }
            }
        }
    }
};
