class Solution {
public:
    int fillCups(vector<int>& amount) {
        priority_queue<int>pq;
        for(int i=0;i<amount.size();i++)
        {
            if(amount[i]>0)
            pq.push(amount[i]);
        }

        int count=0;
        while(pq.size()==3)
        {
            count++;
            int a=pq.top();
            pq.pop();
            int b=pq.top();
            pq.pop();

            if(a-1>0)
            pq.push(a-1);
            if(b-1>0)
            pq.push(b-1);
        }
        if(!pq.empty())
        count+=pq.top();

        return count;


    }
};