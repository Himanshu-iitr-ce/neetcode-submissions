class Solution {
public:
    int rob(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> dp(n+1,0);
        dp[1] = nums[0];
        for(int ind =2;ind<=n;ind++)
        {
            int rob = INT_MIN;
            if(ind-2>=0){rob = nums[ind-1] + dp[ind-2];}
            int notRob = dp[ind-1];
            dp[ind]=max(rob,notRob);
        }
        return dp[n];
        
    }
};
