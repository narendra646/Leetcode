class Solution {
public:
    
    bool isVowel(char c)
    {
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='A' || c=='E' || c=='I' || c=='O' || c=='U')
        return true;

        return false;
    }

    string sortVowels(string s) {
        vector<int>lower(26,0);
        vector<int>upper(26,0);
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' )
            {
                lower[s[i]-'a']++;
            }

            if(s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U' )
            {
                upper[s[i]-'A']++;
            }
        }

        string rep="";
        for(int i=0;i<26;i++)
        {
            if(upper[i]>0)
            {
                char c=i+65;
                while(upper[i]--)
                rep+=c;
            }
        }

   

        for(int i=0;i<26;i++)
        {
            if(lower[i]>0)
            {
                char c=i+97;
                while(lower[i]--)
                rep+=c;
            }
        }

            //  return rep;

        int ind=0;
        for(int i=0;i<s.size();i++)
        {
            if(isVowel(s[i]))
            {
                s[i]=rep[ind++];
            }
        }

        return s;
        
    }
};