class Solution {
public:
    string smallestPalindrome(string s) {
        int n=s.size();
        vector<int>v(26,0);
        char odd='A';
        for(int i=0;i<n;i++)
        v[s[i]-'a']++;

        for(int i=0;i<26;i++)
        {
            if(v[i]%2==1)
            odd=i+'a';
        }
        
        string ans="";
        for(int i=0;i<26;i++)
        {
            if(v[i]>0)
            {
                int num=v[i]%2==0?v[i]:v[i]-1;
                num/=2;
                while(num--)
                ans+=i+'a';
            }
        }
        string t=ans;
        reverse(t.begin(),t.end());

        if(odd!='A')
        ans+=odd;
        ans=ans+t;

        return ans;

    }
};