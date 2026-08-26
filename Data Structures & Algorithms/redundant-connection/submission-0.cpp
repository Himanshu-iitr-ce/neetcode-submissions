class DisjointSet
{
    vector<int> parent,size;
public:
    DisjointSet(int n)
    {
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++)
        {
            parent[i] = i;
        }
    }

    int findUPar(int node)
    {
        if(parent[node] == node)
        return node;

        return parent[node] = findUPar(parent[node]);
    }

    void UnionBySize(int u, int v)
    {
        int par_u = findUPar(u);
        int par_v = findUPar(v);
        if(size[par_u]>size[par_v])
        {
            parent[par_v]=par_u;
            size[par_u] += size[par_v];
        }
        else
        {
            parent[par_u]=par_v;
            size[par_v] += size[par_u];
        }
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) 
    {
        int n = edges.size();
        DisjointSet ds(n);
        vector<int> ans;
        for(auto it: edges)
        {
            int u = it[0];
            int v = it[1];
            if(ds.findUPar(u) != ds.findUPar(v))
            {
                ds.UnionBySize(u,v);
            }
            else{
                ans.push_back(u);
                ans.push_back(v);
                return ans;
            }
        }
    }
};
