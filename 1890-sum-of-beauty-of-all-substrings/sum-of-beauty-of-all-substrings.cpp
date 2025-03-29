class Solution {
public:
    int beautySum(string s) {
        int ans=0;
        int n=s.size();
        for(int i=0;i<s.size();i++)
        {
            int size=i+1;
            int j=0;
            while(j<n-i)
            {
                string m=s.substr(j,size);
                vector<int>fr(26,0);
                for(int k=0;k<m.size();k++)
                {
                    fr[m[k]-'a']++;
                }
                int mini=INT_MAX,maxi=0;
                for(int k=0;k<26;k++)
                {
                    if(fr[k]>0)
                    {
                        mini=min(mini,fr[k]);
                        maxi=max(maxi,fr[k]);
                    }
                }

                ans+=(maxi-mini);

                j++;

            }
        }

        return ans;

    }
};