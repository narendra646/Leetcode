class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        map<int,int>mp;
        int n=nums.size();
        for(int i=0;i<nums.size();i++)
        mp[nums[i]]++;

        int maxi_el=-1,maxi_fre=0;
        for(const auto &pair : mp)
        {
            if(pair.second>maxi_fre)
            {
                maxi_fre=pair.second;
                maxi_el=pair.first;
            }
        }

        int ans=-1;
        int fr=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==maxi_el)
            {
               int size=i+1;
               fr++;
               if(fr*2>size && (maxi_fre-fr)*2>(n-size))
               return size-1;
            }
        }

        return ans;

    }
};