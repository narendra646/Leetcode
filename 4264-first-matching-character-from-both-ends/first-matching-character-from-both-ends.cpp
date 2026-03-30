class Solution {
public:
    int firstMatchingIndex(string s) {
        int n=s.size();
        int i=0,ans=-1;
        while(i<n)
        {
            if(n-i-1>=0 && s[i]==s[n-i-1])
            return i;

            i++;
        }

        return -1;
    }
};