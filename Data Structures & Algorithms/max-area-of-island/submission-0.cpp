class Solution {
private:
    int bfs(int i,int j,vector<vector<int>>&vis,vector<vector<int>>& grid,int n,int m)
    {
        int dR[] ={-1,0,1,0};
        int dC[] ={0,1,0,-1};
        int area = 1;
        queue<pair<int,int>> q;
        q.push({i,j});
        vis[i][j] = 1;
        while(!q.empty())
        {
            int row =q.front().first;
            int col = q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nrow = row+dR[i];
                int ncol = col+dC[i];
                if(nrow >=0 && nrow <n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol] == 1)
                {
                    q.push({nrow,ncol});
                    vis[nrow][ncol] = 1;
                    area++;
                }
            }
        }
        return area;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m =grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int maxAr = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && grid[i][j] == 1)
                {
                    maxAr = max(maxAr,bfs(i,j,vis,grid,n,m));
                }
            }
        }
        return maxAr;
    }
};
