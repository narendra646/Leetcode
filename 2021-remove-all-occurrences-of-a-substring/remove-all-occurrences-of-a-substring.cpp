class Solution {
public:
    string removeOccurrences(string s, string part) {
        stack<char>st;
        string ans="";
        int n=s.size(),m=part.size();
        for(int i=0;i<n;i++)
        {
            int x=part.size();
           st.push(s[i]);
           ans+=s[i];
           if(ans.find(part)!=string::npos)
           {
              while(x && !st.empty())
              {
                st.pop();
                x--;
              }

              string s1="";
              for(int j=0;j<ans.size()-m;j++)
              s1+=ans[j];

              ans=s1;

           }
        }

        return ans;
        
    }
};