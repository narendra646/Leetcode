class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        vector<int>fr(26,0);
        int count=0;
        for(int i=0;i<tasks.size();i++)
        {
            fr[tasks[i]-'A']++;
            count=max(count,fr[tasks[i]-'A']);
        }

        int ans=(count-1)*(n+1);

        for(int i=0;i<26;i++)
        {
            if(fr[i]==count)
            ans++;
        }

        return ans>tasks.size()?ans:tasks.size();
        
    }
};