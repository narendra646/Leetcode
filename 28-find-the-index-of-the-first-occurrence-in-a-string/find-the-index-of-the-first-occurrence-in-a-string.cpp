class Solution {
public:
    int strStr(string haystack, string needle) {
        string s=needle+'#'+haystack;
        int n=s.size();
        vector<int>lps(n,0);
        int pref=0,suff=1;
        while(suff<n)
        {
            if(s[pref]==s[suff])
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
                pref=lps[pref-1];
            }
        }

        for(int i=0;i<n;i++)
        {
            if(lps[i]==needle.size())
            {
                // if(i+1-needle.size()*2<0)
                // return 0;

                return i-needle.size()*2;
            }
        }
        return -1;
    }
};