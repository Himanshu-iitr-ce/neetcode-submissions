class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pr) 
    {
        vector<vector<int>> adjList(n);
        for(int i=0;i<pr.size();i++)
        {
            int u = pr[i][0];
            int v = pr[i][1];
            adjList[v].push_back(u);
        }
        vector<int> indg(n,0);
        for(int i=0;i<n;i++)
        {
            for(auto it: adjList[i])
            {
                indg[it]++;
            }
        }
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(indg[i] == 0)q.push(i);
        }
        vector<int> ans;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto it:adjList[node])
            {
                indg[it]--;
                if(indg[it] == 0) q.push(it);
            }
        }
        if(ans.size() == n) return ans;
        else return {};
    }
};
