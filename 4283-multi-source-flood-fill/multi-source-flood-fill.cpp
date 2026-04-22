class Solution {
public:

    int r,c;
    int row[4]={-1,1,0,0};
    int col[4]={0,0,-1,1};
    bool valid(int a,int b)
    {
       return a>=0&&a<r&&b>=0&&b<c;
    }
    
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        queue<pair<int,pair<int,int>>>q;      // color,row,col
        vector<vector<int>>ans(n,vector<int>(m,0));
        for(int i=0;i<sources.size();i++)
            {
               int rw=sources[i][0],col=sources[i][1];
               ans[rw][col]=sources[i][2];
               q.push({sources[i][2],{rw,col}});
            }
        r=n,c=m;

        
        
        while(!q.empty())
            {
                int s=q.size();\
                map<pair<int,int>,int>mp;
                while(s--)
                    {
                        int cl=q.front().first;
                        int i=q.front().second.first;
                        int j=q.front().second.second;
                        q.pop();
                        for(int k=0;k<4;k++)
                        {
                            if(valid(i+row[k],j+col[k]) && ans[i+row[k]][j+col[k]]==0)
                            { 
                               int rw=i+row[k],cw=j+col[k];
                               if(mp.count({rw,cw}))
                               mp[{rw,cw}]=max(mp[{rw,cw}],cl);
                               else
                               mp[{rw,cw}]=cl;
                            }
                        }
                    }
                    while(!mp.empty()) {
                        auto it = mp.begin();   // get first element
                        pair<int,int> key = it->first;
                        int value = it->second;
                        ans[key.first][key.second]=value;
                        q.push({value,{key.first,key.second}});
                        mp.erase(it);           // remove it
                    }
            }
        return ans;
    }
};