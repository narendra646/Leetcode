class Solution {
public:
    
        int count=0;
     
    int find(vector<int>&v,int num)
    {
        int start=0,end=v.size()-1,index=-1;;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(num>1LL*2*v[mid])
            {
                index=mid;
                start=mid+1;
            }
            else
            end=mid-1;
        }

        if(index==-1)
        return -1;

        // return v.size()-index;
        return index+1;
    }
     
    void merge(vector<int>&arr,int start ,int mid,int end)
    {
       vector<int>temp(end-start+1);
       int left=start,right=mid+1,index=0;
       
       
       vector<int>v;              // to store the right side values 
       for(int i=right;i<=end;i++)
       v.push_back(arr[i]);
       for(int i=left;i<=mid;i++)
       {
           if(find(v,arr[i])!=-1)
           count+=find(v,arr[i]);
       }
       
       
       while(left<=mid && right<=end)                     // merge left and right to form a sorted a array 
       {
           if(arr[left]<=arr[right])
           {
               temp[index]=arr[left];
               index++,left++;
           }
           else
           {
               temp[index]=arr[right];
               index++,right++;
           }
       }
    
       while(left<=mid)
       {
           temp[index]=arr[left];
           index++,left++;
       }
    
       while(right<=end)
       {
           temp[index]=arr[right];
           index++,right++;
       }
    
       index=0;
       while(start<=end)
       {
           arr[start]=temp[index];
           index++,start++;
       }
    }


      void MergeSort(vector<int>&arr , int start , int end)
      {
          if(start>=end)
          return ;
    
          int mid=start+(end-start)/2;
          MergeSort(arr,start,mid);
          MergeSort(arr,mid+1,end);
    
          merge(arr,start,mid,end);
      }
   
    int reversePairs(vector<int>& nums) {
        int l=0,r=nums.size()-1;
        MergeSort(nums,l,r);
        
        return count;
    }
};