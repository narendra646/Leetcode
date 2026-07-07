class Solution {
public:

    void merge(vector<int>& arr,int start,int mid,int end)
    {
        vector<int>temp(end-start+1);
        int left=start,right=mid+1;
        int index=0;
        while(left<=mid && right<=end)
        {
            if(arr[left]<=arr[right])
            {
                temp[index]=arr[left];
                left++;
                index++;
            }
            else
            {
                temp[index]=arr[right];
                right++;
                index++;
            }
        }

        while(left<=mid)
        {
            temp[index]=arr[left];
            left++;
            index++;
        }

        while(right<=end)
        {
            temp[index]=arr[right];
            right++;
            index++;
        }
        // copy the values in the oroginal array 
        index=0;
        for(int i=start;i<=end;i++)
        {
            arr[i]=temp[index];
            index++;
        }
    }

    void mergesort(vector<int>& arr,int start,int end)
    {
        if(start>=end)
        return ;

        int mid=start+(end-start)/2;
        mergesort(arr,start,mid);
        mergesort(arr,mid+1,end);

        merge(arr,start,mid,end);
    }
    vector<int> sortArray(vector<int>& nums) {
        int start=0,end=nums.size()-1;
        mergesort(nums,start,end);
        return nums;
    }
};