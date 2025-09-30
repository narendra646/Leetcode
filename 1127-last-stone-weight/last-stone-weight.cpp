class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {

        priority_queue<int>pq;
        for(int i=0;i<stones.size();i++)
        pq.push(stones[i]);

        while(pq.size()>1)
        {
            int first=pq.top();
            pq.pop();
            first-=pq.top();
            pq.pop();

            if(first)
            pq.push(first);

        }

        return pq.empty()? 0: pq.top();
        
    }
};