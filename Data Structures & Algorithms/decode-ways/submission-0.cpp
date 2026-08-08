class Solution {
private:
    int f(int ind, int n, string& s,vector<int>& dp)
    {
        if(ind >= n) return 1;
        if(dp[ind] != -1) return dp[ind];
        if(s[ind] == '0') return 0;
        int ways = f(ind+1,n,s,dp);
        if(ind+1<n)
        {
            int t = 10*(s[ind]-'0') + s[ind+1]-'0';
            if(t>=10 && t<=26)
            ways+= f(ind+2,n,s,dp);
        }

        return dp[ind]=ways;
    }
public:
    int numDecodings(string s) 
    {
        int n = s.size();
        vector<int> dp(n,-1);
        return f(0,n,s,dp);
        
    }
};
