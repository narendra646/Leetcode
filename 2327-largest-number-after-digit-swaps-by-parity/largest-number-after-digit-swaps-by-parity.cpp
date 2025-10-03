class Solution {
public:
    int largestInteger(int num) {

        string str=to_string(num);
        priority_queue<char>even,odd;

        for(int i=0;i<str.size();i++)
        {
            if((str[i]-'0')%2==0)
            even.push(str[i]);
            else
            odd.push(str[i]);
        }

        for(int i=0;i<str.size();i++)
        {
            if((str[i]-'0')%2==0)
            {
                str[i]=even.top();
                even.pop();
            }
            else
            {
                str[i]=odd.top();
                odd.pop();
            }
        }

        return stoi(str);
        
    }
};