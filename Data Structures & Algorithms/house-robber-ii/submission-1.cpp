class Solution {
private:
    int rob1(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> dp(n+1,0);
        dp[1] = nums[0];
        for(int ind=2;ind<=n;ind++)
        {
            int notRob = 0 + dp[ind-1];
            int rob = nums[ind-1] + dp[ind-2];

            dp[ind]=max(rob,notRob);
        }
        return dp[n];
    }
public:
    int rob(vector<int>& nums) 
    {
        vector<int> temp1,temp2;
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 0) return 0;
        for(int i=0;i<nums.size();i++)
        {
            if(i != 0) temp1.push_back(nums[i]);
            if(i!= nums.size()-1) temp2.push_back(nums[i]);
        }
        return max(rob1(temp1),rob1(temp2));
    }
};
