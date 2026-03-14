class Solution {
public:
    
    void generateStrings(int n,string curr,vector<string>&v)
    {
        if(curr.size()==n)
        {
            v.push_back(curr);
            return;
        }

        vector<char>chr={'a','b','c'};
        for(char c:chr)
        {
            if(curr.empty() || curr.back()!=c)
            {
                generateStrings(n,curr+c,v);
            }
        }
    }

    string getHappyString(int n, int k) {
        vector<string>v;
        generateStrings(n,"",v);
        sort(v.begin(),v.end());

        if(k>v.size())
        return "";

        return v[k-1];
    }
};