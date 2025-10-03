class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool>ans;

        for(int i=0;i<l.size();i++)
        {
            int start=l[i];
            int end=r[i];

            vector<int>v;
            for(int i=start;i<=end;i++)
            v.push_back(nums[i]);
            
            sort(v.begin(),v.end());
            int d=v[1]-v[0];
            bool b=true;
            for(int i=2;i<v.size();i++)
            {
                if((v[i]-v[i-1])!=d)
                b=false;
            }

            ans.push_back(b);
        }

        return ans;
    }
};