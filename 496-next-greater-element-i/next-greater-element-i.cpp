class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>s;
        vector<int>ans(nums2.size(),0);
        for(int i=0;i<nums2.size();i++)
        {
            if(s.empty())
            s.push(i);
            else 
            {
                while(!s.empty() && nums2[i]>nums2[s.top()])
                {
                    ans[s.top()]=nums2[i];
                    s.pop();
                }
                s.push(i);
            }
        }

        while(!s.empty())
        {
            ans[s.top()]=-1;
            s.pop();
        }

        vector<int>nxtgtr(nums1.size());
        for(int i=0;i<nums1.size();i++)
        {
            for(int j=0;j<nums2.size();j++)
            {
                if(nums1[i]==nums2[j])
                {
                   nxtgtr[i]=ans[j];
                }
            }
        }

        return nxtgtr;
    }
};