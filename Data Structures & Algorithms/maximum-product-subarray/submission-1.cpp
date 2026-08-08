class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        int n =nums.size();
        int pre = 1, suf =1;
        int maxi = INT_MIN;
        for(int i=0,j=n-1;i<n,j>=0;i++,j--)
        {
            pre = pre*nums[i];
            suf=suf*nums[j];
            maxi = max(maxi,max(pre,suf));
            if(nums[i] == 0){pre =1;}
            if(nums[j] == 0){suf =1;}
        }
        return maxi;
    }
};
