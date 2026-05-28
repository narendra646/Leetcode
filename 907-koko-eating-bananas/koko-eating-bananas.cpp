class Solution {
public:
    bool isPossible(int mid,int h,vector<int>& piles)
    {
        long long count=0;
        for(int i=0;i<piles.size();i++)
        {
            count+=piles[i]/mid;
            if(piles[i]%mid)
            count++;
        }
        return count<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int start=1,end=0;
        int n=piles.size();
        for(int i=0;i<n;i++)
        {
            end=max(end,piles[i]);
        }
        int ans;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(isPossible(mid,h,piles))
            {
                ans=mid;
                end=mid-1;
            }
            else
            start=mid+1;
        }
        return ans;
    }
};