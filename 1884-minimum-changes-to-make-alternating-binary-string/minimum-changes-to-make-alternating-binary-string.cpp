class Solution {
public:
    int minOperations(string s) {
        string t=s;
        int count1=0,count2=0;
        // even --> 0 , odd-->1
        for(int i=0;i<s.size();i++)
        {
            if(i%2==0)
            {
                if(s[i]=='1')
                count1++;
            }
            else
            {
                if(s[i]=='0')
                count1++;
            }
        }
        // even -->1,odd-->0
        for(int i=0;i<s.size();i++)
        {
            if(i%2==0)
            {
                if(s[i]=='0')
                count2++;
            }
            else
            {
                if(s[i]=='1')
                count2++;
            }
        }

        return min(count1,count2);
    }
};