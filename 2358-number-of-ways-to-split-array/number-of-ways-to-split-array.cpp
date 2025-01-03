class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long count=0;
        long long  p_sum=0;
        for(int i=0;i<nums.size();i++)
        {
           p_sum+=nums[i];
        }
        long long sum1=p_sum,sum2=0;
        for(int i=nums.size()-1;i>0;i--)
        {
            sum1-=nums[i];
            sum2+=nums[i];
            if(sum1>=sum2)
            count++;
        }

        return count;
    }
};