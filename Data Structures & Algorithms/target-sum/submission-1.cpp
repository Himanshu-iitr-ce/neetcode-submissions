class Solution {
private:
    int f(int ind, int k, vector<int>& nums,vector<vector<int>>& dp)
    {
        if(ind == 0)
        {
            if(nums[0] == 0 && k == 0) return 2;
            if(k == 0 || k == nums[0]) return 1;
            else return 0;
        }
        if(dp[ind][k] != -1) return dp[ind][k];

        int pick = 0;
        int notPick = f(ind-1,k,nums,dp);
        if(k>=nums[ind])
        {
            pick = f(ind-1,k-nums[ind],nums,dp);
        }
        return dp[ind][k]=pick+notPick;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) 
    {
        int n = nums.size();
        int totsum =0;
        for(int i=0;i<n;i++)
        {
            totsum+=nums[i];
        }
        if(totsum < abs(target) || (totsum - target) % 2 != 0) return 0;
        int tg = (totsum - target) / 2;
        vector<vector<int>> dp(n,vector<int>(tg+1,-1));
        return f(n-1,tg,nums,dp); 
    }
};
