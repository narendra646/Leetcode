class Solution {
public:
    long long smallestOddDivisor(long long n)
    {
        for(long long i = 3; i * i <= n; i += 2)
        {
            if(n % i == 0)
                return i;
        }
        return n; 
    }
    long long minimumMaxValue(int n, int index, int value) {
        if(value==1)
        return -1;

        long long ans=-1;
        if(value%2==0)
        {
            int d=(value-2)/2;
            if(d<index)
            return -1;
            
            ans=value;
            
            ans+=(n-1-index)*2;
            // while(index!=n-1)
            // {
            //    ans+=2;
            //    index++;
            // }
        }
        else
        {
           int div=smallestOddDivisor(value);
           int d=(value-div)/2;
           if(d<index)
           return -1;
           
           ans=value;
           if(index!=n-1)
           {
             ans+=div;
             index++;
           }
           
           ans+=(n-1-index)*2;

        //    while(index!=n-1)
        //    {
        //        ans+=2;
        //        index++;
        //    }
        }
        return ans;
    }
};