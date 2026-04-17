class Solution {
public:
    int Reverse(int n)
    {
        int num=0;
        while(n)
        {
           int r=n%10;
           num=r+num*10;
           n/=10;
        }
        return num;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> prev;
        int ans = n + 1;
        for (int i = 0; i < n; ++i) {
            int x = nums[i];
            if (prev.count(x)) {
                ans = min(ans, i - prev[x]);
            }
            prev[Reverse(x)] = i;
        }

        return ans == n + 1 ? -1 : ans;

    }
};