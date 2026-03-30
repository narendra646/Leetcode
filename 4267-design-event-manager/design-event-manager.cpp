class EventManager {
public:
    struct Compare{
        bool operator()(pair<int,int>a, pair<int,int>b){
            if(a.first!=b.first) return a.first < b.first;
            return a.second>b.second;          
        }
    };
 priority_queue<pair<int,int>, vector<pair<int,int>>, Compare> pq;
 map<int,int>mp;

   int removedId=-1;
    EventManager(vector<vector<int>>& events) {
        for(auto it:events)
        {
            int id=it[0],pr=it[1];
            pq.push({pr,id});
            mp[id]=pr;
        }
    }
    
    void updatePriority(int eventId, int newPriority) {
       mp[eventId]=newPriority;
       pq.push({newPriority,eventId});
    }
    
    int pollHighest() {
           while(!pq.empty()){
            auto x = pq.top();
            if(!mp.count(x.second)) pq.pop();
            else if(mp[x.second]!=x.first){ pq.pop();}
            else break;
        }

        if(!pq.empty())
        {
            int ans = pq.top().second;
            pq.pop();
            mp.erase(ans);
            return ans;
        }
        return -1;

    }
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */