class Solution {
public:
    vector<int> maxPrimes(int n, int s) {
        vector<int>prime(n+1,1);
        prime[0]=0,prime[1]=0;
        for (int i = 2; i * i <= n; i++)
        {
            if (prime[i] == 1)
            {
                for (int j = i * i; j <= n; j += i)
                {
                    prime[j] = 0;
                }
            }
        }
       long long p=0;
       vector<int>ans;
       for(int i=0;i<=n;i++)
       {
         if(prime[i]==1)
         {
            p+=i;
            if(p<=s)
            ans.push_back(i);
         }
       }

       return ans;

    }
};