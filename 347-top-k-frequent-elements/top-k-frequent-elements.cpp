class Solution {
public:
    struct Comparator{
        bool operator()(const pair<int,int>&p1,const pair<int,int>&p2)
        {
            return p1.second<p2.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
       unordered_map<int,int>mp;
       for(int i=0;i<nums.size();i++)
       mp[nums[i]]++;

       priority_queue<pair<int,int>, vector<pair<int,int>> , Comparator>pq;
       for(auto &p:mp)
       {
          pq.push({p.first,p.second});
       } 
       vector<int>ans;
       while(k--)
       {
          ans.push_back(pq.top().first);
          pq.pop();
       }
       return ans;


    }
};