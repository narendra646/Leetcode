class Solution {
public:
    string longestPrefix(string s) {
        int n=s.size();
        vector<int>lps(n,0);
        int pref=0,suff=1;
        while(suff<n)
        {
            if(s[suff]==s[pref])
            {
                lps[suff]=pref+1;
                suff++,pref++;
            }
            else
            {
                if(pref==0)
                {
                    lps[suff]=0;
                    suff++;
                }
                else
                {
                   pref=lps[pref-1];
                }
            }
        } 

        // return lps[n-1];
        string ans="";
        for(int i=0;i<lps[n-1];i++)
        ans+=s[i];

        return ans;
    }
};