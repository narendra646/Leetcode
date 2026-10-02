class Solution {
public:
    void parenthesis(int n,int left,int right,vector<string>&gp,string &temp)
    {
        if(left+right==2*n)
        {
            gp.push_back(temp);
            return;
        }
        if(left<n)
        {
            temp.push_back('(');
            parenthesis(n, left+1, right, gp, temp);
            temp.pop_back();
        }
        if(right<left)
        {
            temp.push_back(')');
            parenthesis(n, left, right+1, gp, temp);
            temp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>gp;
        string temp;
        parenthesis(n,0,0,gp,temp);

        return gp;
    }
};