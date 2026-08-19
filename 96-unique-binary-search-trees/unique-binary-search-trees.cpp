class Solution {
public:
    int numTrees(int n) {
        vector<int>dp(n+1);
        dp[0]=1;
        for(int node=1;node<=n;node++)
        {
            for(int root=1;root<=node;root++)
            {
                dp[node]+=dp[root-1]*dp[node-root];
            }
        }

        return dp[n];

    }
};