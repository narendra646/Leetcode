class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n=s.size();
        map<char,int>m1;
        for(int i=0;i<n;i++)
        {
            m1[s[i]]++;
        }

        int i=0;
        vector<int>v(26,0);
        int count=0;
        vector<int>ans;
        while(i<n)
        {
            count++;
            m1[s[i]]--;
            v[s[i]-'a']++;
            bool b=true;
            for(int j=0;j<26;j++)
            {
               if(v[j]!=0)
               {
                  char c='a'+j;
                  if(m1[c]!=0)
                  b=false;
               }
            }

            if(b==true)
            {
                ans.push_back(count);
                count=0;
            }

            i++;

        }

        return ans;
    }
};