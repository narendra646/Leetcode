class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
       int n=arr.size();
        priority_queue<pair<double,pair<int,int>>,vector<pair<double,pair<int,int>>>,greater<pair<double,pair<int,int>>>>pq;
        for(int i=0;i<n-1;i++)
        {
            double d=1.0*(double)arr[i]/arr[n-1];
            pq.push(make_pair(d,make_pair(i,n-1)));
        }
        
        pair<int,int>el;
        while(--k)
        {
           el=pq.top().second;
           pq.pop();

            if (el.second - 1 > el.first) {
                double d = (double)arr[el.first] / arr[el.second - 1];
                pq.push({d, {el.first, el.second - 1}});
            }


        }

         auto [i, j] = pq.top().second;
        return {arr[i], arr[j]};

    }
};