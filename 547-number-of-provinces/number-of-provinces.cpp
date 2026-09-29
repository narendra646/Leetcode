class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size(); 
        vector<int>visited(n,0);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(visited[i]==1)
            continue;

            queue<int>q;
            q.push(i);
            visited[i]=1;
            while(!q.empty())
            {
                int node=q.front();
                q.pop();
                for(int v=0;v<n;v++)
                {
                    if(isConnected[node][v]==1 && visited[v]==0)
                    {
                        visited[v]=1;
                        q.push(v);
                    }
                }
            }
            ans++;
        }
        return ans;
    }
};