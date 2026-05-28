class Solution {
public:
    bool isMaximum(int mid,int m,vector<int>& position)
    {
        int count=1,val=position[0];
        for(int i=1;i<position.size();i++)
        {
            if(position[i]>=val+mid)
            {
                count++;
                val=position[i];
            }
        }
        return count>=m;
    }
    int maxDistance(vector<int>& position, int m) {
        int start=1,end=0,n=position.size();
        for(int i=0;i<n;i++)
        end=max(end,position[i]);

        sort(position.begin(),position.end());

        int ans=0;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(isMaximum(mid,m,position))
            {
                ans=mid;
                start=mid+1;
            }
            else
            end=mid-1;
        }

        return ans;
    }
};