class Solution {
public:
    int numberOfSubstrings(string s) {
        // first method

    //     int n=s.size(),ans=0;  
    //     int left=0,right=0;
    //     vector<int>v(3, 0);
    //     while(right<n)
    //     {
    //         v[s[right]-'a']++;

    //         while(v[0]>0 && v[1]>0 && v[2]>0 )
    //         {
    //             ans+=n-right;

    //             v[s[left]-'a']--;
    //             left++;
    //         }
    //         right++;
    //     }
    //    return ans;


          // *********** second method *******

    int n=s.size();
    vector<int>v={-1,-1,-1};
    int ans=0,k=0;
    for(int i=0;i<n;i++)
    {
        v[s[i]-'a']=k;
        k++;


        ans+=1+min({v[0],v[1],v[2]});

    }

    return ans;



    }


};