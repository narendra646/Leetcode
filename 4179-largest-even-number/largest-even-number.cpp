class Solution {
public:
    string largestEven(string s) {
        int n=s.size()-1;
        while(n>=0 && s[n]=='1')
        n--;

        string ans="";
        for(int i=0;i<=n;i++)
        ans+=s[i];

        return ans;

    }
};