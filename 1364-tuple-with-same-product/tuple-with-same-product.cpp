class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int,int>mp;
        int count=0;
        for(int i=0;i<nums.size()-1;i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                int mul=nums[i]*nums[j];
                 mp[mul]++;
             
            }
        }

        for(auto & p:mp)
        {
            int a=p.second;
            count+=(a*(a-1))/2;
        }

        return  count*8;

        
    }
};