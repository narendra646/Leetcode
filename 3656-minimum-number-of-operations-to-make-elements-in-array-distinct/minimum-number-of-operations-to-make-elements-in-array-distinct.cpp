class Solution {
public:
    bool distinct(vector<int>array,int left,int right)
    {
        unordered_map<int,int>mp;
        for(int i=left;i<right;i++)
            {
                mp[array[i]]++;
            }
        for(const auto& p:mp)
            {
                if(p.second>1)
                    return 0;
            }
        return 1;
    }
    int minimumOperations(vector<int>& nums) {
        int count=0;
        int i=0;
        while(i<nums.size())
            {
                if(!distinct(nums,i,nums.size()))
                {
                    count++;
                    i+=3;
                }
                else
                {
                    break;
                }
            }
        return count;

    }
};