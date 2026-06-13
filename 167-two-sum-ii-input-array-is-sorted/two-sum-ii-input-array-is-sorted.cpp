class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int>ans={-1,-1};
        int n=numbers.size();
        for(int i=0;i<n-1;i++)
        {
            int start=i+1,end=n-1;
            int new_tar=target-numbers[i];
            while(start<=end)
            {
                int mid=start+(end-start)/2;
                if(numbers[mid]==new_tar)
                {
                    ans={i+1,mid+1};
                    break;
                }
                else if(numbers[mid]<new_tar)
                start=mid+1;
                else
                end=mid-1;
            }
        }

        return ans;
    }
};