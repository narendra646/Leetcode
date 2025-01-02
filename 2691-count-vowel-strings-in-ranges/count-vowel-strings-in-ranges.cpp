class Solution {
public:
    bool is_vowel(string s)
    {
        if((s[0]=='a'|| s[0]=='e'|| s[0]=='i'|| s[0]=='o'|| s[0]=='u' ) && (s[s.size()-1]=='a'|| s[s.size()-1]=='e'|| s[s.size()-1]=='i'|| s[s.size()-1]=='o'|| s[s.size()-1]=='u'))
        return 1;
        else
        return 0;
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        // vector<int>ans;
        // for(int i=0;i<queries.size();i++)
        // {
        //     long long start=queries[i][0];
        //     long long end=queries[i][1];
        //     long long count=0;
        //     for(int j=start;j<=end;j++)
        //     {
        //         string s=words[j];
        //         if(is_vowel(s))
        //         {
        //             count++;
        //         }
        //     }
        //     ans.push_back(count);
        // }
        // return ans;



        vector<int>v(words.size(),0);
        for(int i=0;i<words.size();i++)
        {
            string s=words[i];
            if(is_vowel(s))
            {
                v[i]=1;
            }
        }


        int psum =0;
        vector<int>sum;
        for(int i=0;i<v.size();i++)
        {
            psum+=v[i];
            sum.push_back(psum);
        }

        // return sum;

        

        vector<int>ans;
        for(int i=0;i<queries.size();i++)
        {
            int start=queries[i][0];
            int end=queries[i][1];
            if(start==0)
            {
                ans.push_back(sum[end]-0);
            }
            else
            {
                ans.push_back(sum[end]-sum[start-1]);
            }
        }

        return ans;




    }
};