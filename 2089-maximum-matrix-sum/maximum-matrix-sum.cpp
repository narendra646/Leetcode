class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long ans=0;
        int count=0;
        int mini=INT_MAX;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[i].size();j++)
            {
                ans+=abs(matrix[i][j]);
                mini=min(mini,abs(matrix[i][j]));
                if(matrix[i][j]<0)
                count++;
            }
        }
        
        if(count%2==0)
        return ans;

        return ans-2*mini;

    }
};