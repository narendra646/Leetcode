class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int count=0;
        int i=0;
        string word="";
        while(i<text.size())
        {
           if(text[i]!=' ')
           {
              word+=text[i];
              i++;
           }
           else
           {
              bool b=true;
              for(int j=0;j<word.size();j++)
              {
                 if(brokenLetters.find(word[j])!=string::npos)
                 {
                    b=false;
                    break;
                 }
              }
              if(b)
              count++;
              
              i++;
              word="";

           }
        }

        word="";
        i=text.size()-1;
        while(i>=0 && text[i]!=' ')
        {
            word+=text[i];
            i--;
        }
         
         bool b=true;
        for(int j=0;j<word.size();j++)
        {
            if(brokenLetters.find(word[j])!=string::npos)
            {
                b=false;
                break;
            }
        }

        if(b)
        count++;

        return count;
    }
};