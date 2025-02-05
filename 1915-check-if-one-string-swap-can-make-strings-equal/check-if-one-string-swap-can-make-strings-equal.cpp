class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        vector<int>v1(26,0);
        vector<int>v2(26,0);
        for(int i=0;i<s1.size();i++)
        {
            v1[s1[i]-'a']++;
            v2[s2[i]-'a']++;
        }
        for(int i=0;i<26;i++)
        {
            if(v1[i]!=v2[i])
            return false;
        }
        int count=0;
        for(int i=0;i<s1.size();i++)
        {
            if(s1[i]!=s2[i])
            count++;

        }

        if(count==0 || count==2)
        return true;
        else
        return false;
    }
};