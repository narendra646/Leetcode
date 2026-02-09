class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++)
        sum+=nums[i];

        int count=0;
        for(int i=0;i<nums.size()-1;i++)
        {
            sum-=nums[i];

            if(nums[i]>sum/(nums.size()-i-1))
            count++;
        }

        return count;

    }
};