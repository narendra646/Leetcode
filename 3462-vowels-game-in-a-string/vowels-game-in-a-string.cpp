class Solution {
public:
    bool doesAliceWin(string s) {
        int count=0;
        int even=0,odd=0;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')
            {
                count++;
            }
            else
            {
                if(count!=0)
                {
                    if(count%2==0)
                    even++;
                    else
                    odd++;

                    count=0;
                }
            }
        }

                if(count!=0)
                {
                    if(count%2==0)
                    even++;
                    else
                    odd++;

                    count=0;
                }
        if(odd==0 && even==0)
        return false;
        // else if(odd>=even || (odd==0 && even!=0))
        // return true;
        else
        return true;
    }
};