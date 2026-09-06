class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>topo;
        vector<int>indeg(numCourses,0);
        vector<vector<int>>adj(numCourses);
        for(int i=0;i<prerequisites.size();i++)
        {
            int u=prerequisites[i][0],v=prerequisites[i][1];
            adj[v].push_back(u);
            indeg[u]++;
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++)
        {
            if(indeg[i]==0)
            q.push(i);
        }

        while(!q.empty())
        {
            int node=q.front();
            topo.push_back(node);
            q.pop();
            for(int i=0;i<adj[node].size();i++)
            {
                indeg[adj[node][i]]--;
                if(indeg[adj[node][i]]==0)
                q.push(adj[node][i]);
            }
        }

        if(topo.size()==numCourses)
        return true;

        return false;
    }
};