class Solution {
public:
    void premutations(vector<int>& nums,vector<vector<int>>&ans,int index,int n)
    {
        if(index==n-1)
        {
            ans.push_back(nums);
            return;
        }

        for(int i=index;i<n;i++)
        {
            swap(nums[index],nums[i]);
            premutations(nums,ans,index+1,n);
            swap(nums[index],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ans;
        int index=0;
        premutations(nums,ans,index,n);
        return ans;
    }
};