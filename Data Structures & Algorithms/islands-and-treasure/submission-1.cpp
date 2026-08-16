class Solution {
private:
    void bfs(vector<vector<int>>& grid,int n, int m,queue<pair<int,pair<int,int>>> q)
    {
        vector<int> dr= {-1,0,1,0};
        vector<int> dc= {0,1,0,-1};
        vector<vector<int>> vis(n,vector<int>(m,0));
        while(!(q.empty()))
        {
            int r = q.front().second.first;
            int c =q.front().second.second;
            int dis = q.front().first;
            q.pop();
            vis[r][c] = 1;
            for(int i=0;i<4;i++)
            {
                int nrow = r+dr[i];
                int ncol = c+dc[i];
                if(nrow >=0 && nrow <n && ncol >=0 && ncol<m && (grid[nrow][ncol] != -1 && grid[nrow][ncol] !=0) && vis[nrow][ncol] != 1)
                {
                    grid[nrow][ncol] = min(dis+1,grid[nrow][ncol]);
                    q.push({grid[nrow][ncol],{nrow,ncol}});
                    vis[nrow][ncol] = 1;
                }
            }

        }

    }
public:
    void islandsAndTreasure(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,pair<int,int>>>q;
        for(int i=0;i<n;i++)
        {
            for(int j =0;j<m;j++)
            {
                if(grid[i][j] == 0)
                q.push({0,{i,j}});
            }
        }
        bfs(grid,n,m,q);
    }
};
