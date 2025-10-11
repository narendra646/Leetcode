class Solution {
public:
    string decodeString(string s) {
        stack<string>st;
        for(int i=0;i<s.size();i++)
        {
            if(st.empty())
            st.push(string(1,s[i]));
            else
            {
                if(s[i]!=']')
                {
                    st.push(string(1,s[i]));
                }
                else
                {
                    string t="";
                    while(!st.empty() && st.top()!="[")
                    {
                        // t+=st.top();
                        t=st.top()+t;
                        st.pop();
                    }
                    st.pop();
                    string d="";
                    while(!st.empty() && isdigit(st.top()[0]))
                    {
                        d=st.top()+d;
                        st.pop();
                    }
                    
                    // reverse(t.begin(),t.end());
                    int k=stoi(d);
                    string temp="";
                    while(k--)
                    {
                        temp+=t;
                    }
                    
                    st.push(temp);
                }
            }
        }

          string ans="";
        while(!st.empty())
        {
            ans=st.top()+ans;
            st.pop();
        }
        
        return ans;

    }
};