class Solution {
private:
    bool detect(int src, vector<int>& vis, vector<vector<int>>& adj)
    {
        queue<pair<int,int>> q;
        q.push({src,-1});
        vis[src] = 1;
        while(!q.empty())
        {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(auto it: adj[node])
            {
                if(!vis[it])
                {
                    q.push({it,node});
                    vis[it] = 1;
                }
                else if(parent != it) return true;
            }
        }
        return false;
    }
public:
    bool validTree(int n, vector<vector<int>>& edges) 
    {
        vector<vector<int>>adj(n);
        vector<int> vis(n,0);
        for(int i=0;i<edges.size();i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        bool ans = false;
        int cnt = 0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                ans = ans||detect(i,vis,adj);
                cnt++;
            }
        }
        if(cnt > 1) return false;
        return !ans;
        

    }
};
