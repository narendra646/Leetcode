class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        for(int i=0;i<grid.size();i++)
        {
            sort(grid[i].begin(),grid[i].end(),greater<int>());
        }

        vector<long long>v;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<limits[i];j++)
            {
                v.push_back(grid[i][j]);
            }
        }

        sort(v.begin(),v.end(),greater<long long>());

        long long ans=0;
        for(int i=0;i<k;i++)
        {
            ans+=v[i];
        }

        return ans;
    }
};