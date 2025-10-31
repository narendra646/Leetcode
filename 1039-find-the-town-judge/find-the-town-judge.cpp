class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>indeg(n,0);
        vector<int>outdeg(n,0);

        for(int i=0;i<trust.size();i++)
        {
            int u=trust[i][0]-1;
            int v=trust[i][1]-1;
            outdeg[u]++;
            indeg[v]++;
        }

        int ans=-1;
        for(int i=0;i<n;i++)
        {
            if(outdeg[i]==0 && indeg[i]==n-1)
            {
                ans=i;
                break;
            }
        }

       return ans==-1?-1:ans+1;

    }
};