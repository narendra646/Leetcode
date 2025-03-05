class Solution {
public:
    long long coloredCells(int n) {
        long long k=n;
        k--;
        long long ans=0;
        int i=1;
        while(k--)
        {
           ans+=i;
           i+=2;
        }
        ans*=2;
        ans+=(2*n)-1;

        return ans;
    }
};