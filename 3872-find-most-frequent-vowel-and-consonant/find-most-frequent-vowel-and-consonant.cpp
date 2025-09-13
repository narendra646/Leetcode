class Solution {
public:
    int maxFreqSum(string s) {

        vector<int>v(26,0);
        for(int i=0;i<s.size();i++)
        {
            v[s[i]-'a']++;
        }

        int vowel=0,conso=0;
        for(int i=0;i<26;i++)
        {
           if(i==0 || i==4 || i==8 || i==14 || i==20)
           vowel=max(vowel,v[i]);
           else
           conso=max(conso,v[i]);
        }

        return vowel+conso;
        
    }
};