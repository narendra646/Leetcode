class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n=nums.size();
        vector<pair<int,int>>p(n);      // first value is index and the second is value
        vector<int>ans;
        for(int i=0;i<n;i++){
           p[i].first=i;
           p[i].second=nums[i];
        }

    sort(p.begin(), p.end(), [](pair<int, int>& a, pair<int, int>& b) {
        return a.second > b.second;
      });


    sort(p.begin(), p.begin() + k, [](pair<int, int>& a, pair<int, int>& b) {
        return a.first < b.first;
    });

    for(int i=0;i<k;i++)
    {
        ans.push_back(p[i].second);
    }

    return ans;

        
    }
};