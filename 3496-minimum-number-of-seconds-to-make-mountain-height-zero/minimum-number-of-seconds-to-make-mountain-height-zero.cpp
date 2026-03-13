class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
       long long H=*max_element(workerTimes.begin(), workerTimes.end());
       long long start=1,end=(H)*mountainHeight*(mountainHeight+1)/2;
       long long ans=0;
       while(start<=end)
       {
            long long mid=start+(end-start)/2;
            long long count=0;
            for(int i=0;i<workerTimes.size();i++)
            {
                long long work=mid/workerTimes[i];
                // let this worker reduces the height by k
                long long k=(-1+sqrt(1+8*work))/2;
                count+=k;
            }
            if(count>=mountainHeight)
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