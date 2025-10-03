class Solution {
public:
    int maxProduct(vector<int>& nums) {

        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<2;i++)
        {
            pq.push(nums[i]);
        }

        for(int i=2;i<nums.size();i++)
        {
            if(nums[i]>pq.top())
            {
                pq.push(nums[i]);
                pq.pop();
            }
        }

        int i=pq.top();
        pq.pop();
        int j=pq.top();

        return (i-1)*(j-1);
        
    }
};