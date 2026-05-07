class Solution {

   struct Compare {
    bool operator()(pair<char,pair<int,int>>a, pair<char,pair<int,int>>b) {
        if (a.second.first== b.second.first) {
            return a.second.second>b.second.second;
        }
        return a.second.first<b.second.first;
    }
};
public:
    bool isVowel(char c)
    {
        return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
    }
    string sortVowels(string s) {
        //  character,frequency,first_occurance
        priority_queue<pair<char,pair<int,int>>,vector<pair<char,pair<int,int>>>,Compare> pq;
        unordered_map<char,int>fr,occ;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
           if(isVowel(s[i]))
           fr[s[i]]++;
        }
        

        for(int i=n-1;i>=0;i--)
        {
            if(isVowel(s[i]))
            occ[s[i]]=i;
        }


        for(auto it:fr)
        {
            char c=it.first;
            int f=it.second;
            int oc=occ[c];
            pq.push({c,{f,oc}});
        }
        int i=0;
        while(!pq.empty())
        {
            char c=pq.top().first;
            int a=pq.top().second.first;
            pq.pop();
            while(a && i<n)
            {
                if(isVowel(s[i]))
                {
                    s[i]=c;
                    a--;
                }
                i++;
            }
        }
        return s;
    }
};