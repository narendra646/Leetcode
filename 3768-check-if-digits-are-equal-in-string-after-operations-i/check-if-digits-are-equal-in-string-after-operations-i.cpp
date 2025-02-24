class Solution {
public:
    bool hasSameDigits(string s) {
        string op=s;
        while(op.size()>2)
        {
            string m="";
            for(int i=0;i<op.size()-1;i++)
            {
                int a=(op[i]-'0')+(op[i+1]-'0');
                a=a%10;
                m+=a+'0';
            } 
            op=m;
        }
        if(op[0]-'0'==op[1]-'0')
        return 1;
        else
        return 0;
        
    }
};