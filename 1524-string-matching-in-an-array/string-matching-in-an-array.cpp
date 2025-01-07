class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string>v;
        for(int i=0;i<words.size();i++)
        {
            for(int j=0;j<words.size();j++)
            {
                if(i!=j && words[j].find(words[i])!=string::npos)
                v.push_back(words[i]);
            }
        }
        vector<string>ans;
        if(v.empty())
        return ans;
        
        for(int i=0;i<v.size()-1;i++)
        {
            if(v[i]!=v[i+1])
            ans.push_back(v[i]);
        }
        ans.push_back(v[v.size()-1]);
        return ans;
    }
};