class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int maxi=nums[nums.size()-1];
        int x=k;
        while(x<=maxi)
        {
            bool b=0;
            for(int i=0;i<nums.size();i++)
            {
               if(nums[i]==x)
               b=1;
            }
            if(!b)
            return x;

            x+=k;
        }
        
        maxi++;
        while(maxi%k!=0)
        maxi++;

        return maxi;
    }
};