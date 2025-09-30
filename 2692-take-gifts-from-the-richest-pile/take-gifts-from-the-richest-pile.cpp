class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int>pq;
        for(int i=0;i<gifts.size();i++)
        pq.push(gifts[i]);

        long long ans=0;

        while(k-- && !pq.empty())
        {
           if(sqrt(pq.top()))
           pq.push(sqrt(pq.top()));

           pq.pop();
        }

        if(pq.empty())
        return 0;

        while(!pq.empty())
        {
            ans+=pq.top();
            pq.pop();
        }

        return ans;
        
    }
};