class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) 
    {
        vector<int> dis(n+1, 1e9);
        dis[0]=0;
        dis[k]=0;
        int ans = INT_MIN;
        for(int i=0;i<n-1;i++)
        {
            for(auto it: times)
            {
                int u = it[0];
                int v = it[1];
                int t = it[2];
                if(dis[u]!= 1e9 && dis[u]+t < dis[v])
                {
                    dis[v] = dis[u] + t;
                }
            }
        }
        for(int i=0;i<dis.size();i++)
        {
            if(dis[i] == 1e9) return -1;
            ans = max(ans,dis[i]);
        }
        return ans;
        
    }
};
