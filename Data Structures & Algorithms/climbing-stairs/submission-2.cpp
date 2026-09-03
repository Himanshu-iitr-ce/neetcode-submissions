class Solution {
public:
    int climbStairs(int n) 
    {
        vector<int> dp(n+1,0);
        dp[0] = 1;
        for(int ind=1;ind<=n;ind++)
        {
            int oneStep =  dp[ind-1];
            int twoStep = 0;
            if(ind-2>=0){twoStep = dp[ind-2];}
            dp[ind]=oneStep+twoStep;
        }
        return dp[n];
    }
};
