class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans=1;
        int count=1;
        for(int i=1;i<nums.size();i++)
        {
           if(nums[i]>nums[i-1])
           {
             count++;
             ans=max(ans,count);
           }
           else
           count=1;
        }

        int ans1=0;
        int count1=1;
        for(int i=1;i<nums.size();i++)
        {
           if(nums[i]<nums[i-1])
           {
             count1++;
             ans1=max(ans1,count1);
           }
           else
           count1=1;
        }

        return max(ans1,ans);

    }
};