class Solution {
public:
     
    int countPalindromicSubsequence(string s) {
     
      int ans=0;
      unordered_set<char>str;
      for(int i=0;i<s.size();i++)
      str.insert(s[i]);


      for(char letter : str)
      {
         int i=-1,j=0;
         for(int k=0;k<s.size();k++)
         {
            if(s[k]==letter)
            {
                if(i==-1)
                i=k;

                j=k;
            }
         }

         unordered_set<char>between;
         for(int l=i+1;l<j;l++){
         between.insert(s[l]);
         }

         ans+=between.size();
      }

      return ans;
       
    }
};