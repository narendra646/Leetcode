class Solution {
public:
    bool isTrionic(vector<int>& nums) {

        bool b=1;
        int count=0; 
        int i=0;
        int ind=0;
        while(i<nums.size()-1)
        {
            if(nums[i]>=nums[i+1])
            {

                count++;
                
                if((i-ind)+1<=1)
                {
                    b=0;
                }
                ind=i;
                break;
            }
            i++;
        }

        while(i<nums.size()-1)
        {
            if(nums[i]<=nums[i+1])
            {
                count++;
                
                if((i-ind)+1<=1)
                {
                    b=0;
                }
                ind=i;
                break;
            }
            i++;
        }

        while(i<nums.size()-1)
        {
            if(nums[i]>=nums[i+1])
            {
                count++;
                
                if((i-ind)+1<=1)
                {
                    b=0;
                }
                ind=i;
                
                break;
            }
            i++;
        }
        
        
        if(count==2 && b)
        return true;
        else
        return false;

        
    }
};