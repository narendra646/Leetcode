class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            int n=nums[i];
            int sum=0,div=0;
            for(int fact=1;fact<=sqrt(n);fact++)
            {
                if(n%fact==0)
                {
                    int other=n/fact;

                    if(other==fact)
                    {
                     div+=1;
                     sum+=fact;
                    }
                    else
                    {
                     div+=2;
                     sum+=fact+other;
                    }
                }
            }
            if(div==4)
            {
                ans+=sum;
            }
        }

        return ans;
    }
};