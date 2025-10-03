class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<score.size();i++)
        {
            pq.push(make_pair(score[i],i));
        }

        vector<string>ans(score.size());
        
        if(!pq.empty())
        {
           pair<int,int>el;
           el=pq.top();

           pq.pop();

           ans[el.second]="Gold Medal";
        }

        if(!pq.empty())
        {
           pair<int,int>el;
           el=pq.top();

           pq.pop();

           ans[el.second]="Silver Medal";
        }

        if(!pq.empty())
        {
           pair<int,int>el;
           el=pq.top();

           pq.pop();

           ans[el.second]="Bronze Medal";
        }


        int k=4;
        while(!pq.empty())
        {
            ans[pq.top().second]=to_string(k);
            pq.pop();

            k++;
        }

        return ans;
    }
};