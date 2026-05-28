class Solution {
public:
    bool isPossible(int mid,int k,vector<int>& nums)
    {
        int count=1,sum=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            sum+=nums[i];
            if(sum>mid)
            {
                count++;
                sum=nums[i];
            }
        }

        return count<=k;
    }
    int splitArray(vector<int>& nums, int k) {
        int start=0,end=0,n=nums.size();
        for(int i=0;i<n;i++)
        {
            start=max(start,nums[i]);
            end+=nums[i];
        }
        int ans=0;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(isPossible(mid,k,nums))
            {
                ans=mid;
                end=mid-1;
            }
            else
            start=mid+1;
        }

        return ans;
    }
};