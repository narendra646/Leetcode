class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n=nums.size();
        vector<int>temp=nums;
        for(int i=0;i<n;i++){
            temp[i]=nums[i];
        }
        sort(temp.begin(),temp.end());
        int left=(n-1)/2;
        int right=n-1;
        for(int i=0;i<n;i+=2){ 
            nums[i]=temp[left];
            left--;
        }
        for(int i=1;i<n;i+=2){
            nums[i]=temp[right];
            right--;
        }
    }
};