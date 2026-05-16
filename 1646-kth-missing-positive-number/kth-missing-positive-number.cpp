class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        // int ans=-1;
        // int n=arr.size();
        // int end=arr[n-1]+k;
        // for(int i=1;i<=end;i++)
        // {
        //     bool b=false;
        //     for(int j=0;j<n;j++)
        //     {
        //         if(arr[j]==i)
        //         {
        //             b=true;
        //             break;
        //         }
        //     }
        //     if(b==false)
        //     {
        //         k--;
        //     }
        //     if(k==0)
        //     {
        //         ans=i;
        //         break;
        //     }
        // }
        // return ans;

                 int n=arr.size();
        vector<int>v(n);
        v[0]=arr[0]-1;
        for(int i=1;i<n;i++)
        {
            v[i]=v[i-1]+(arr[i]-arr[i-1]-1);
        }
        int ind=-1,val=0;
        int start=0,end=n-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(v[mid]>=k)
            {
                ind=mid;
                val=v[mid];
                end=mid-1;
            }
            else
            start=mid+1;
        }
        
        if(ind==-1)
        return arr[n-1]+k-v[n-1];
        
        int missing=arr[ind]-(val-k+1);
        
        return missing;

    }
};