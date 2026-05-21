class Solution {
public:
     int countDigit(int n)
     {
        int count=0;
        while(n)
        {
            count++;
            n/=10;
        }
        return count;
     }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int>mp1,mp2;
        for(int i=0;i<arr1.size();i++)
        {
            int a=arr1[i];
            while(a)
            {
               mp1[a]++;
               a/=10;
            }
        }
        for(int i=0;i<arr2.size();i++)
        {
            int a=arr2[i];
            while(a)
            {
               mp2[a]++;
               a/=10;
            }
        }

        int ans=0;
        for(int i=0;i<arr1.size();i++)
        {
            int a=arr1[i];
            while(a)
            {
                if(mp2[a])
                {
                    ans=max(ans,countDigit(a));
                }
                a/=10;
            }
        }

        for(int i=0;i<arr2.size();i++)
        {
            int a=arr2[i];
            while(a)
            {
                if(mp1[a])
                {
                    ans=max(ans,countDigit(a));
                }
                a/=10;
            }
        }

        return ans;
    }
};