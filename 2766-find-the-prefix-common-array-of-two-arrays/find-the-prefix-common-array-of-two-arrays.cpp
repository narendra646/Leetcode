class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int>ans;
        int n=A.size();
        for(int i=0;i<A.size();i++)
        {
            vector<int>v1(n+1,0);
            vector<int>v2(n+1,0);
            for(int j=0;j<=i;j++)
            {
                v1[A[j]]++;
                v2[B[j]]++;
            }
            int count=0;
            for(int i=0;i<v1.size();i++)
            {
                if(v1[i]!=0 && v2[i]!=0)
                count++;
            }
            ans.push_back(count);
        }

        return ans;
    }
};