class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>color(n,-1);     // initially all nodes are uncoloured 
        queue<int>q;
        for(int j=0;j<n;j++)
        {
            if(color[j]==-1)
            {
                color[j]=0;
                q.push(j);
                while(!q.empty())
                {
                    int node=q.front();
                    q.pop();
                    for(int i=0;i<graph[node].size();i++)
                    {
                        if(color[graph[node][i]]==-1)
                        {
                            color[graph[node][i]]=(color[node]+1)%2;
                            q.push(graph[node][i]);
                        }
                        else
                        {
                            if(color[graph[node][i]]==color[node])
                            return false;
                        }
                    }
                }
            }
        }

        return true;
    }
};