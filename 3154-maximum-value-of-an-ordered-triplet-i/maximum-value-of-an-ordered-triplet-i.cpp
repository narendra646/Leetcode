class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long ans=0,n=nums.size();
        for(int i=0;i<n-2;i++)
        {
            for(int j=i+1;j<n-1;j++)
            {
                long long d=nums[i]-nums[j];
                long long b=0;
                for(int k=j+1;k<n;k++)
                {
                    b=d*nums[k];
                     if(b>0)
                    ans=max(ans,b);
                }

            }

        }

        return ans;
    }
};