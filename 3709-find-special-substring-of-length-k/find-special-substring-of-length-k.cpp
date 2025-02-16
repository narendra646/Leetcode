class Solution {
public:
    bool hasSpecialSubstring(string s, int k) {
        
        if(k==1)
        {
            if(s.size()==1)
            return true;
        }



        int start=0,end=k-1;
        while(start+k<=s.size())
        {
            bool b=true;
            for(int i=start;i<end;i++)
            {
                if(s[i]!=s[i+1])
                {
                    b=false;
                    break;
                }
            }

            if(b==true)
            {
                if(start==0)
                {
                    if(s[end+1]!=s[start])
                    return true;
                }
                else if(end==s.size()-1)
                {
                    if(s[start]!=s[start-1])
                    return true;
                }
                else 
                {
                    if(s[start-1]!=s[start] && s[end+1]!=s[start])
                    return true;
                }
            }

            start++,end++;
        }

        return false;
    }
};