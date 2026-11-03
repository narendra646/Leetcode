class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& locked, int k) {
        int n = nums.size();
        int unlock=0,swp=0;
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {

                if (nums[j] > nums[j + 1]) {
                    if(locked[j]==1)
                    {
                        locked[j]=0;
                        unlock++;
                    }
                    if(locked[j+1]==1)
                    {
                        locked[j+1]=0;
                        unlock++;
                    }
                    swap(nums[j], nums[j + 1]);
                    swp++;
                }
            }
        }
        return unlock<=k?(unlock+swp):-1;

    }
};