class Solution {
public:
    int minOperations(vector<int>& nums) {
        if(nums.size()==1)
        return 0;

        bool b1=0;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]!=nums[i-1])
            {
                b1=1;
                break;
            }
        }

        if(b1==0)
        return 0;
        else
        return 1;

        // int i=1;
        // int ans;
        // bool b=0;
        // while(i<nums.size())
        // {
        //   ans=nums[i]&nums[i-1];
        //   if(ans==0)
        //   {
        //     b=1;
        //     break;
        //   }
        //   i++;
        // }
        // if(b==1)
        // return 1;

        // return 0;

    }
};