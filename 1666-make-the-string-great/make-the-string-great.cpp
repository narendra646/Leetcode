class Solution {
public:
    bool are_same(char c1,char c2)
    {
        return (tolower(c1)==tolower(c2) && isupper(c1)!=isupper(c2) && islower(c1)!=islower(c2));
    }
    string makeGood(string s) {
        stack<char>st;
        for(int i=0;i<s.size();i++)
        {
            if(st.empty())
            st.push(s[i]);
            else
            {
                // if(are_same(s[i],st.top()))
                // {
                //     while(!st.empty() && are_same(s[i],st.top()))
                //     st.pop();
                // }
                // else
                // st.push(s[i]);

                if(!st.empty() && (tolower(st.top()) == tolower(s[i])) && (isupper(st.top()) != isupper(s[i])))
                st.pop();
                else
                st.push(s[i]);

            }
        }

        string ans="";
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }

        reverse(ans.begin(),ans.end());

        return ans;
        
    }
};