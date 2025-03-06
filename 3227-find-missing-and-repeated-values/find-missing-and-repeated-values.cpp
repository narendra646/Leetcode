class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<int>v;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                v.push_back(grid[i][j]);
            }
        }

        sort(v.begin(),v.end());
        


        int rep,mis;
        for(int i=1;i<=n*n;i++)
        {
           bool b=0;
           for(int j=0;j<v.size();j++)
           {
             if(v[j]==i)
             b=1;
           }
           if(b==0)
           {
             mis=i;
             break;
           }
        }

        for(int i=0;i<v.size()-1;i++)
        {
            if(v[i]==v[i+1])
            {
                rep=v[i];
            }
        }

        return {rep,mis};
    }
};