class Solution {
private:
    void bfs(int src,vector<int>& vis, vector<vector<int>>& adj )
    {
        queue<int>q;
        q.push(src);
        vis[src] = 1;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            for(auto it:adj[node])
            {
                if(!vis[it])
                {
                    q.push(it);
                    vis[it]=1;
                }
            }
        }
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) 
    {
        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int cnt = 0;
        vector<int>vis(n,0);
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                cnt++;
                bfs(i,vis,adj);
            }
        }
        return cnt;

    }
};
