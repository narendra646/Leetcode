class Solution {
public:
    int longestPalindrome(string s) {
        vector<int>low(26,0);
        vector<int>up(26,0);
        for(int i=0;i<s.size();i++)
        {
            if(s[i]>='a' && s[i]<='z')
            {
                low[s[i]-'a']++;
            }
            else
            up[s[i]-'A']++;
        }
        
        int ans=0;
        for(int i=0;i<26;i++)
        {
           if(low[i]%2==0)
           ans+=low[i];

           if(up[i]%2==0)
           ans+=up[i];
        }

        int count=0;
        for(int i=0;i<26;i++)
        {
            if(low[i]%2==1)
            {
                ans+=low[i]-1;
                count++;
            }

            if(up[i]%2==1)
            {
                ans+=up[i]-1;
                count++;
            }
          
        }

        if(count>0)
        return ans+1;

        return ans;

        
    }
};