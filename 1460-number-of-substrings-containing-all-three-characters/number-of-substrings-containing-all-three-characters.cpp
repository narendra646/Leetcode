class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size(),ans=0;  
        int left=0,right=0;
        vector<int>v(3, 0);
        while(right<n)
        {
            v[s[right]-'a']++;

            while(v[0]>0 && v[1]>0 && v[2]>0 )
            {
                ans+=n-right;

                v[s[left]-'a']--;
                left++;
            }
            right++;
        }

       return ans;

    }


};