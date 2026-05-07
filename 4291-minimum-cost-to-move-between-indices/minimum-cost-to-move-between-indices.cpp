class Solution {
public:
    vector<int> minCost(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int>right(n,0);
        vector<int>left(n,0);

        // we are calculatuing the cost to move in the right direction 
        for(int i=0;i<n-1;i++)
        {
            int cost=0;
            if(i==0 || (nums[i+1]-nums[i])<(nums[i]-nums[i-1]))
            {
                cost=1;          // means to move on to the right adjcent is possible with cost 1 
            }
            else 
            {
                cost=nums[i+1]-nums[i];
            }
            right[i+1]=right[i]+cost;     ////   right[i+1] represents the cost required to reach at i+1
        }

        for(int i=1;i<n;i++)
        {
            int cost=0;
            if(i==n-1 || nums[i]-nums[i-1]<=nums[i+1]-nums[i])
            cost=1;
            else
            cost=nums[i]-nums[i-1];

            left[i]=cost;
            if(i)
            left[i]+=left[i-1];
        }

        vector<int>ans;
        for(int i=0;i<queries.size();i++)
        {
            int l=queries[i][0];
            int r=queries[i][1];
            if(l<r)
            ans.push_back(right[r]-right[l]);
            else if(l>r)
            ans.push_back(left[l]-left[r]);
            else
            ans.push_back(0);
        }

        return ans;

    }
};