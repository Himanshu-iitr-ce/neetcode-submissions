class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) 
    {
        int n =cost.size();
        vector<int> dp(n+1,0);
        for(int ind = n-1;ind>=0;ind--)
        {
            int one = cost[ind] + dp[ind+1];
            int two = 1e9;
            if(ind+2<=n)
            two = cost[ind] + dp[ind+2];
            dp[ind]=min(one,two);
        }
        return min(dp[0],dp[1]);
    }
};
