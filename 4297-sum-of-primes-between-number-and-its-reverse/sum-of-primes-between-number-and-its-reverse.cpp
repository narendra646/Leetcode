class Solution {
public:
    int sumOfPrimesInRange(int n) {
    string s=to_string(n);
    reverse(s.begin(),s.end());
    int n1=stoi(s);

    // int limit=max(n,n1)+1;
    // vector<bool> isPrime(limit+1, true);
    // isPrime[0] = isPrime[1] = false;
    // for (int i = 2; i * i <= limit; i++) {
    //     if (isPrime[i]) {
    //         for (int j = i * 2; j <= limit; j += i) {
    //             isPrime[j] = false;
    //         }
    //     }
    // }

    // int limit=max(n,n1)+1;
    vector<bool> isPrime(1001, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= 1000; i++) {
        if (isPrime[i]) {
            for (int j = i * 2; j <= 1000; j += i) {
                isPrime[j] = false;
            }
        }
    }

    int ans=0;
    if(n>=n1)
    {
       for(int i=n1;i<=n;i++)
       {
        if(isPrime[i])
        ans+=i;
       }
    }
    else
    {
       for(int i=n;i<=n1;i++)
       {
        if(isPrime[i])
        ans+=i;
       }
    }
    return ans;
    }
};