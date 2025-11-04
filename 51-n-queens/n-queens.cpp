class Solution {
public:

    bool check(int n,vector<string>&Board,int i,int j)
    {
        int row=i,co=j;
        // upper left diagonal
        while(row>-1 && co>-1)
        {
            if(Board[row][co]=='Q')
            return 0;

            row--,co--;
        }

        row=i,co=j;
        while(row>-1 && co<n)
        {
            if(Board[row][co]=='Q')
            return 0;

            row--,co++;
        }

        return 1;
    }

    void find(int row,int n, vector<vector<string>>&ans,vector<string>&Board,vector<bool>&col)
    {
        // base case

        if(row==n)
        {
            ans.push_back(Board);
            return ;
        }
        

        for(int j=0;j<n;j++)
        {
           if(col[j]==0 && check(n,Board,row,j))
           {
              col[j]=1;
              Board[row][j]='Q';
              find(row+1,n,ans,Board,col);
              col[j]=0;
              Board[row][j]='.';
           }
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        vector<vector<string>>ans;
        vector<string>Board(n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            Board[i].push_back('.');
        }

        vector<bool>col(n,0);
        
        find(0,n,ans,Board,col);
        
        return ans;
    }
};