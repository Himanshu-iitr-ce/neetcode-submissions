class Solution {
private:
    int f(int ind, vector<int>& coins, int amount,vector<vector<int>>& dp)
    {
        if(ind == 0)
        {
            if(amount%coins[0] == 0) return 1;
            return 0;
        }
        if(dp[ind][amount] != -1) return dp[ind][amount];
        //pick
        int pick = 0;
        if(amount>=coins[ind])
        pick =  f(ind,coins,amount-coins[ind],dp);
        //not pick
        int notpick =  f(ind-1,coins,amount,dp);

        return dp[ind][amount]=pick+notpick;
    }
public:
    int change(int amount,vector<int>& coins) 
    {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1,-1));
        return f(n-1,coins, amount,dp);
    }
};
