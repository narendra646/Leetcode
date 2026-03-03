class Solution {
public:
    string flipandreverse(string &s)
    {
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(s[i]=='0')
            s[i]='1';
            else
            s[i]='0';
        }

        reverse(s.begin(),s.end());
        return s;
    }
    char findKthBit(int n, int k) {
        string s="0";
        for(int i=2;i<=n;i++)
        {
            string str=s+'1';
            str+=flipandreverse(s);
            s=str;
        }

        return s[k-1];
    }
};