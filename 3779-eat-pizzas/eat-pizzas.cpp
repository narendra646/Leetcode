class Solution {
public:
    long long maxWeight(vector<int>& pizzas) {
        sort(pizzas.begin(),pizzas.end());
        long long ans=0,n=pizzas.size();

        long long m=n/4;
        // long long odd=ceil(m/2);
        long long odd=(m+1)/2;
        long long even=m-odd;
        
        // long long ind=n-odd;
        // for(int i=ind;i<n;i++)
        // {
        //     ans+=pizzas[i];
        // }
        
        long long i=n-1;
        while(odd--)
        { 
            ans+=pizzas[i];
            i--;
        }

        
        while(even--)
        {
            i--;
            ans+=pizzas[i];
            i--;
        }

        return ans;
        
    }
};