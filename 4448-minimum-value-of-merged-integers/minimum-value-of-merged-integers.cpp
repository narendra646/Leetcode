class Solution {
public:
    int minMergedInteger(vector<int>& nums) {
        int ans=INT_MAX;
        for(int i=0;i<nums.size();i+=2)
        {
            int  n=nums[i+1];
            int d=0;
            while(n)
            {
                d++;
                n/=10;
            }
            int new_num=nums[i]*pow(10,d)+nums[i+1];
            ans=min(ans,new_num);
        }
        return ans;
    }
};