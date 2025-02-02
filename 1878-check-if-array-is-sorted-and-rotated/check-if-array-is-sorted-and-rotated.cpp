class Solution {
public:
   
   void rotate(vector<int>&arr)
   {
     int n=arr.size();
     int temp=arr[n-1];
     for(int i=n-2;i>=0;i--)
     {
        arr[i+1]=arr[i];
     }
     arr[0]=temp;
   }
    bool check(vector<int>& nums) {
        int k=nums.size();
        vector<int>v(nums);
        sort(v.begin(),v.end());
        for(int i=0;i<k;i++)
        {
            rotate(v);
            if(v==nums)
            return true;
        }

        return false;
    }
};