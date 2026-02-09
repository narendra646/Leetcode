class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        int n=nums.size();
        stack<long long>s;
        for(int i=0;i<n;i++)
        {
            if(s.empty())
            s.push(nums[i]);
            else
            {
                if(s.top()==nums[i])
                {
                    long long el=nums[i];
                    while(!s.empty() && el==s.top())
                    {
                        el+=s.top();
                        s.pop();
                    }
                    s.push(el);
                }
                else
                s.push(nums[i]);
            }
        }
        vector<long long>ans;
        while(!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};