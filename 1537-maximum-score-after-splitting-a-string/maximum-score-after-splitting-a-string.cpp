class Solution {
public:
    int maxScore(string s) {
        int n=s.size(),ans=0;
        for(int i=0;i<s.size()-1;i++)
        {
            int c0=0,c1=0;
            for(int j=0;j<=i;j++)
            {
                if(s[j]=='0')
                c0++;
            }
            for(int j=i+1;j<s.size();j++)
            {
                if(s[j]=='1')
                c1++;
            }
            ans=max(ans,c0+c1);
        }

        return ans;
    }
};