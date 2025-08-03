class Solution {
public:
    int maxBalancedShipments(vector<int>& weight) {
        
        int ans=0,n=weight.size();
        int maxi=INT_MIN;
        for(int i=0;i<n;i++)
        {
            if(weight[i]<maxi)
            {
                ans++;
                maxi=INT_MIN;
            }
            else
            {
                maxi=max(maxi,weight[i]);
            }
        }

        return ans;

    }
};