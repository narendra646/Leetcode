class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        int count_0=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
            count_0++;
        }

        if(count_0==0)
        {
            int product=1;
            for(int i=0;i<n;i++)
            product*=nums[i];

            for(int i=0;i<n;i++)
            nums[i]=product/nums[i];

            return nums;
        }
        else if(count_0==1)
        {
            int product=1;
            for(int i=0;i<n;i++)
            {
                if(nums[i]!=0)
                product*=nums[i];
            }

            for(int i=0;i<n;i++)
            {
                if(nums[i]==0)
                nums[i]=product;
                else
                nums[i]=0;
            }

            return nums;
        }
        else
        {
            vector<int>temp(n,0);
            return temp;
        }
    }
};