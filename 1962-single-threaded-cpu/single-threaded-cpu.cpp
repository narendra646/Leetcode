class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {

        long long n=tasks.size();
        for(int i=0;i<n;i++)
        tasks[i].push_back(i);

        sort(tasks.begin(),tasks.end());
        long long timer=tasks[0][0];
        long long i=0;

      vector<int>ans;
        priority_queue<pair<long long,long long> ,vector<pair<long long,long long>>,greater<pair<long long,long long>>>pq;
    while(!pq.empty() || i<n){    
        while(i<n && tasks[i][0] <= timer)
        {
            pq.push({tasks[i][1],tasks[i][2]});
            i++;
        }

        if(pq.empty())
        {
           timer=tasks[i][0];
        }
        else
        {
            ans.push_back(pq.top().second);
            timer+=pq.top().first;
            pq.pop();
        }
    }

        return ans;
        
    }
};