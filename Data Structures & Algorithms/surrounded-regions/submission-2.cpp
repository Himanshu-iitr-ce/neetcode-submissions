class Solution {
private:
    void bfs(int row, int col,vector<vector<char>>& grid,vector<vector<int>>& vis )
    {
        queue<pair<int,int>> q;
        int n= grid.size();
        int m =grid[0].size();
        q.push({row,col});
        vis[row][col] = 1;
        int dr[] = {-1,0,1,0};
        int dc[]=  {0,1,0,-1};
        while(!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nr = r+dr[i];
                int nc = c+dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc] == 'O' && !vis[nr][nc])
                {
                    q.push({nr,nc});
                    vis[nr][nc] = 1;
                }
            }
        }
        return;
    }
public:
    void solve(vector<vector<char>>& grid) 
    {
        int n= grid.size();
        int m =grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            if(grid[i][0] == 'O' && !vis[i][0])
            bfs(i,0,grid,vis);
            if(grid[i][m-1] == 'O' && !vis[i][m-1])
            bfs(i,m-1,grid,vis);
        }
        for(int j=0;j<m;j++)
        {
            if(grid[0][j] == 'O' && !vis[0][j])
            bfs(0,j,grid,vis);
            if(grid[n-1][j] == 'O' && !vis[n-1][j])
            bfs(n-1,j,grid,vis);
        }
        for(int i=1;i<n-1;i++)
        {
            for(int j=1;j<m-1;j++)
            {
                if(grid[i][j] == 'O' && !vis[i][j])
                grid[i][j] = 'X';
            }
        }
        
    }
};
