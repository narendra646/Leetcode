class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int>v;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                v.push_back(grid[i][j]);
            }
        }

        sort(v.begin(),v.end());
        int trget=v[v.size()/2];
        int ans=0;
        for(int i=0;i<v.size();i++)
        {
           int d=abs(v[i]-trget);
           int r=d%x;
           if(r==0)
           ans+=d/x;
           else
           return -1;
        }

        return ans;
    }
};