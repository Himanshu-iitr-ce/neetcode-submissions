class Solution {
private:
    pair<int,int> bfs(queue<pair<int,int>>& q,vector<vector<int>>& grid, int n, int m,vector<vector<int>> &vis)
    {
        int fresh_vis = 0;
        int tot_minutes = 0;
        while(!(q.empty()))
        {
            vector<int> dr = {-1,0,1,0};
            vector<int> dc = {0,1,0,-1};
            tot_minutes++;
            int p = q.size();
            for(int i=0;i<p;i++)
            {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                for(int k=0;k<4;k++)
                {
                    int nrow = row+dr[k];
                    int ncol = col+ dc[k];
                    if(nrow >=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol] == 1 && !vis[nrow][ncol])
                    {
                        fresh_vis ++;
                        q.push({nrow,ncol});
                        vis[nrow][ncol] = 1;
                    }
                }
            }
        }
        return {tot_minutes-1,fresh_vis};
    }
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
       queue<pair<int,int>> q;
       int n = grid.size();
       int m = grid[0].size();
       if(n == m && n == 1 && grid[0][0] == 0)
        return 0;
       int tot_good = 0;
       vector<vector<int>> vis(n,vector<int>(m,0));
       for(int i=0;i<n;i++)
       {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 2)
                {
                q.push({i,j});
                vis[i][j] =1;
                }
                else if(grid[i][j] == 1)tot_good++;
            }
       }
       pair<int,int> ans = bfs(q,grid,n,m,vis);
       if(ans.second == tot_good) return max(ans.first,0);
       else return -1;

    }
};
