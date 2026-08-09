class Solution {
private:
    bool f(int ind, int sum, vector<int>& nums,vector<vector<int>>& dp)
    {
        if(ind < 0)
        {
            if(sum == 0) return true;
            else return false;
        }
        if(dp[ind][sum] != -1) return dp[ind][sum];
        bool pick = false;
        bool notPick = f(ind-1, sum,nums,dp);
        if(sum>=nums[ind])
        {
            pick = f(ind-1,sum-nums[ind],nums,dp);
        }
        return dp[ind][sum]=pick||notPick;
    }
public:
    bool canPartition(vector<int>& nums) 
    {
        int n = nums.size();
        int totsum = 0;
        for(int i=0;i<n;i++)
        {
            totsum += nums[i];
        }
        if(totsum % 2 != 0) return false;
        vector<vector<int>> dp(n,vector<int>((totsum/2)+1,-1));
        return f(n-1,totsum/2,nums,dp);
        
    }
};
