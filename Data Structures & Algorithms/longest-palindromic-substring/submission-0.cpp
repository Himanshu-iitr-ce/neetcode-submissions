#include<bits/stdc++.h>
class Solution {
public:
    string longestPalindrome(string s) 
    {
        string t ="#";
        int n =s.size();
        for(int i=0;i<n;i++)
        {
            t+=s[i];
            t+="#";
        }
        int maxlen = 0;
        int start = -1;
        for(int i=0;i<t.size();i++)
        {
            int l = i-1;
            int r=i+1;
            while(l>=0 && r<=t.size())
            {
                if(t[l] != t[r]) break;
                l--;
                r++;
            }
            if(r-l-1 > maxlen)
            {
                maxlen =r-l-1;
                start = l+1;
            }
        }

        string ans ="";
        for(int i = start; i<(start+maxlen);i++)
        {
            if(t[i] != '#')ans+=t[i];
        }
        return ans;
    }
};
