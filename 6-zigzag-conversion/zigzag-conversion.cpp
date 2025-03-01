class Solution {
public:
    string convert(string s, int numRows) {

        if(numRows==1 || numRows>s.size())
        return s;

        vector<vector<char>>S(numRows);
        int i=0,jump=0;
        for(char c:s)
        {
            S[i].push_back(c);
            if(i==0)
            jump=1;
            else if(i==numRows-1)
            jump=-1;

            i+=jump;
        }
        
        string ans="";

        for(const auto & row:S)
        {
            for(char c:row)
            ans+=c;
        }

        return ans;
        
    }
};