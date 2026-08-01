class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
         if(k==1)
         return nums;

         vector<int>v;
         deque<int>dq;

         for(int i=0;i<k;i++)
         {
            if(dq.empty())
            dq.push_back(i);

            while(!dq.empty() && nums[dq.back()]<nums[i])
            dq.pop_back();

            dq.push_back(i);
         }

         v.push_back(nums[dq.front()]);

         for(int i=k;i<nums.size();i++)
         {
            while(!dq.empty() && nums[dq.back()]<nums[i])
            dq.pop_back();

            dq.push_back(i);

            while(!dq.empty() && dq.front()<i-k+1)
            dq.pop_front();

            v.push_back(nums[dq.front()]);

         }

         return v;


    }
}; 