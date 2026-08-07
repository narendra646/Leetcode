class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        long long ans=INT_MIN;
        for(int i=0;i<nums.size();i++)
            {
                for(int j=0;j<nums.size();j++){
                    // if(i!=j)
                    
                        // long long a=nums[i]*nums[j];
                        // long long b=gcd(nums[i],nums[j]);
                        long long a=nums[i]/gcd(nums[i],nums[j]);
                        long long b=nums[j]/gcd(nums[i],nums[j]);
                        long long c=a*b;
                        ans=max(ans,c);
                    
                }
            }
        return ans;
    }
};