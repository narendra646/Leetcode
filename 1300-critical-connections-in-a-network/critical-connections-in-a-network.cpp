class Solution {
public:

   void DFS(int node,int parent,vector<vector<int>> &adj,vector<bool>&visited,vector<int>&disc,vector<int>&low,vector<vector<int>>&ans,int &count)
   {
       disc[node]=low[node]=count;
       visited[node]=1;
       for(int j=0;j<adj[node].size();j++)
       {
          int neigh=adj[node][j];
          if(neigh==parent)
          continue;
          else if(visited[neigh])
          low[node]=min(low[node],low[neigh]);
          else
          {
             count++;
             DFS(neigh,node,adj,visited,disc,low,ans,count);
             if(low[neigh]>disc[node])
             {
                vector<int>temp;
                temp.push_back(node);
                temp.push_back(neigh);
                ans.push_back(temp);
             }
             low[node]=min(low[node],low[neigh]);
          }
       }
   }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
       vector<vector<int>>ans;
        vector<vector<int>>adj(n);
        for(int i=0;i<connections.size();i++)
        {
            int u=connections[i][0];
            int v=connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int>disc(n);
        vector<int>low(n);
        vector<bool>visited(n,0);
        int count=0;

        DFS(0,-1,adj,visited,disc,low,ans,count);

        return ans;
        
    }
};