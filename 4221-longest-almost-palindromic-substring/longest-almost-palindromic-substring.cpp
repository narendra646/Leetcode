class Solution {
public:   
    int almostPalindromic(string s) {
        int n=s.size();
        int ans=2;
        for(int i=0;i<n;i++)
        {
            // for odd length
            int l=1;
            int b=1;
            for(int j=i-1,k=i+1;j>=0 || k<n;j--,k++)
            {
                if(j>=0 && k<n && s[j]==s[k])
                l+=2;
                else if(b)
                k--,l++,b--;                  // move left
                else
                break;
            }
            ans=max(ans,l);
            l=1,b=1;
            for(int j=i-1,k=i+1;j>=0 || k<n;j--,k++)
            {
                if(j>=0 && k<n && s[j]==s[k])
                l+=2;
                else if(b)
                j++,l++,b--;                  // move right
                else
                break;
            }
            ans=max(ans,l);
            // even length
            l=0,b=1;
            for(int j=i,k=i+1;j>=0 || k<n;j--,k++)
            {
                if(j>=0 && k<n && s[j]==s[k])
                l+=2;
                else if(b)
                k--,l++,b--;                  // move left
                else
                break;
            }
            ans=max(ans,l);
            l=0,b=1;
            for(int j=i,k=i+1;j>=0 || k<n;j--,k++)
            {
                if(j>=0 && k<n && s[j]==s[k])
                l+=2;
                else if(b)
                j++,l++,b--;                  // move right
                else
                break;
            }
            ans=max(ans,l);
            
        }
        return ans;
    }
};