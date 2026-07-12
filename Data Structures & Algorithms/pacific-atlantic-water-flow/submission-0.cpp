class Solution {
public:


    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    void dfs(vector<vector<int>>& heights,
             int i,
             int j,
             vector<vector<int>>& vis) {

        vis[i][j] = 1;

        int n = heights.size();
        int m = heights[0].size();

        for(int k = 0; k < 4; k++) {

            int ni = i + dx[k];
            int nj = j + dy[k];

            if(ni >= 0 && nj >= 0 &&
               ni < n && nj < m &&
               !vis[ni][nj] &&
               heights[ni][nj] >= heights[i][j]) {

                dfs(heights, ni, nj, vis);
            }
        }
    }



    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>> pacific(n, vector<int>(m, 0));
        vector<vector<int>> atlantic(n, vector<int>(m, 0));
        
        for(int i = 0; i < n; i++)
            dfs(heights, i, 0, pacific);

        for(int j = 0; j < m; j++)
            dfs(heights, 0, j, pacific);

        for(int i = 0; i < n; i++)
            dfs(heights, i, m - 1, atlantic);

        for(int j = 0; j < m; j++)
            dfs(heights, n - 1, j, atlantic);

        vector<vector<int>> ans;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(pacific[i][j] && atlantic[i][j]) {
                    ans.push_back({i, j});
                }

            }
        }

        return ans;
    }
};
