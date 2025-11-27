class Solution {
public:
  int count(int i,vector<int>&dp)
  {
     if(i<=1)
     return 1;

     if(dp[i]!=-1)
     return dp[i];

     return dp[i]= count(i-1,dp)+count(i-2,dp);
  }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return count(n,dp);
        
    }
};