class Solution {
private:
    bool isPresent(string temp, vector<string>& wordDict)
    {
        for(auto it : wordDict)
        {
            if(it == temp) return true;
        }
        return false;
    }
    bool f(int ind, string s, vector<string>& wordDict,vector<int>& dp)
    {
        if(ind == s.size()) return true;
        if(dp[ind] != -1) return dp[ind];
        bool ans = false;
        string temp = "";
        for(int i=ind; i<s.size();i++)
        {
            temp+=s[i];
            bool check = isPresent(temp,wordDict) && f(i+1,s,wordDict,dp);
            ans = ans || check;
        }
        return dp[ind]=ans;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        int n =s.size();
        vector<int> dp(n,-1);
        return f(0,s,wordDict,dp);
        
    }
};
