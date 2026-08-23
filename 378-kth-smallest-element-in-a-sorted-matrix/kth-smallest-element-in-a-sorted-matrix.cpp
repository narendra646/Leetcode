class Solution {
public:

    int count(int n,vector<vector<int>>& mat,int k,int target)
    {
        // count the values that are less than mid 
        int i=n-1,j=0;      // start with lower left corner
        int count=0;
        while(i>=0 && j<n)
        {
            if(mat[i][j]>target)
            i--;
            else
            {
                count+=i+1;
                j++;
            }
        }
        return count;

    }

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int low=matrix[0][0],high=matrix[n-1][n-1];
        int ans=-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(count(n,matrix,k,mid)<k)
            low=mid+1;
            else
            high=mid-1;
        }

        return low;
    }
};