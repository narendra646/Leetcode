class Solution {
public:
    void generateAll(int n,string curr,vector<string>&ans)
    {
        if(curr.size()==n)
        {
            ans.push_back(curr);
            return ;
        }
        generateAll(n,curr+'0',ans);
        generateAll(n,curr+'1',ans);
    }
    vector<string> generateValidStrings(int n, int k) {
        vector<string>v;
        generateAll(n,"",v);
        
        vector<string>ans;
        for(int j=0;j<v.size();j++)
        {
            string s=v[j];
            // check validity
            bool b=true;
            for(int i=0;i<n-1;i++)
            {
                if(s[i]=='1' && s[i+1]=='1')
                b=false;
            }
            // calculate cost
            int cost=0;
            for(int i=0;i<n;i++)
            {
                if(s[i]=='1')
                cost+=i;
            }

            if(b && cost<=k)
            ans.push_back(s);
        }

        return ans;

    }
};