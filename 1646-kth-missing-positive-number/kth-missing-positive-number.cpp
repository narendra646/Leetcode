class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int ans=-1;
        int n=arr.size();
        int end=arr[n-1]+k;
        for(int i=1;i<=end;i++)
        {
            bool b=false;
            for(int j=0;j<n;j++)
            {
                if(arr[j]==i)
                {
                    b=true;
                    break;
                }
            }
            if(b==false)
            {
                k--;
            }
            if(k==0)
            {
                ans=i;
                break;
            }
        }
        return ans;
    }
};