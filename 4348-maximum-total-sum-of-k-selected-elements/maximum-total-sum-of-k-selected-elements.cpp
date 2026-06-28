class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        sort(nums.begin(),nums.end());
        int i=nums.size()-1;
        long long ans=0;
        while(i>=0 && k>0)
        {
            if(mul>0)
            {
                ans+=1LL*nums[i]*mul;
                i--,mul--,k--;
            }
            else
            {
                ans+=nums[i];
                i--,mul--,k--;
            }
        }

        return ans;
        
    }
};