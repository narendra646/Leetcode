class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n=derived.size();
        vector<int>v1(n);
        vector<int>v2(n);
        v1[0]=0,v2[0]=1;
        for(int i=1;i<n;i++)
        {
            v1[i]=derived[i-1]^v1[i-1];
            v2[i]=derived[i-1]^v2[i-1];
        }

        if((v1[0]^v1[n-1])==derived[n-1] || (v2[0]^v2[n-1])==derived[n-1])
        return true;
        else
        return false;
    }
};