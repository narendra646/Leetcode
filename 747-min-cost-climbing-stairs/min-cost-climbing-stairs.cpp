class Solution {
public:
   
   int count(int i,vector<int>& cost,vector<int>&dp)
   {
      if(i<=1)
      return 0;
      
      if(dp[i]!=-1)
      return dp[i];
    
      return dp[i]= min(cost[i-1]+count(i-1,cost,dp),cost[i-2]+count(i-2,cost,dp));
   }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int>dp(cost.size()+1,-1);
         return count(cost.size(),cost,dp);
    }
};