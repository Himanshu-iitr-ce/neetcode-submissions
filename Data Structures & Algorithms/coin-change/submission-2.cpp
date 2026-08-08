class Solution {
private:
    int f(int ind, vector<int>& coins, int amount,vector<vector<int>>& dp)
    {
        if(ind == 0)
        {
            if(amount%coins[0] == 0) return amount/coins[0];
            return 1e9;
        }
        if(dp[ind][amount] != -1) return dp[ind][amount];
        //pick
        int pick = INT_MAX;
        if(amount>=coins[ind])
        pick = 1+ f(ind,coins,amount-coins[ind],dp);
        //not pick
        int notpick = 0+ f(ind-1,coins,amount,dp);

        return dp[ind][amount]=min(pick,notpick);
    }
public:
    int coinChange(vector<int>& coins, int amount) 
    {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1,-1));
        int ans = f(n-1,coins, amount,dp);
        if(ans == 1e9) return -1;
        else return ans;
    }
};
