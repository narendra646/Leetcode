class Solution {
public:
    int n,m;
    bool isValid(int i,int j)
    {
        return i>=0&&i<n&&j>=0&&j<m;
    }
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        n=grid.size(),m=grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        visited[0][0]=1;

        int r=0,c=0;

        while(true)
        {
            int i,j;
            if(grid[r][c]=='R')
            i=r,j=c+1;
            else if(grid[r][c]=='L')
            i=r,j=c-1;
            else if(grid[r][c]=='U')
            i=r-1,j=c;
            else if(grid[r][c]=='D')
            i=r+1,j=c;
  
            if(!isValid(i,j) || (isValid(i,j) && visited[i][j]==1))
            break;

            r=i,c=j;
            visited[r][c]=1;
        }

        return {r,c};

    }
};