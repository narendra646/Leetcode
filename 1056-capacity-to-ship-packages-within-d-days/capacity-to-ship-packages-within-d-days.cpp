class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int start=0,end=0;
        for(int i=0;i<n;i++)
        {
            start=max(start,weights[i]);
            end+=weights[i];
        }
        int ans=-1;

        while(start<=end)
        {
            int cap=start+(end-start)/2;
            int sum=0,count=1;
            for(int i=0;i<n;i++)
            {
                if(sum+weights[i]<=cap)
                {
                    sum+=weights[i];
                }
                else
                {
                    count++;
                    sum=weights[i];
                }
            }
            if(count>days)
            {
                start=cap+1;
            }
            else
            {
                ans=cap;
                end=cap-1;
            }
        }

        return ans;

    }
};