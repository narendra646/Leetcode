class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n=fruits.size();
        int count=0;
        vector<int>v(n,0);
        for(int i=0;i<n;i++)
        {
            bool b=0;
            for(int j=0;j<n;j++)
            {
               if(v[j]==0 && baskets[j]>=fruits[i])
               {
                 v[j]=1;
                 count++;
                 b=1;
               }
               if(b)
               break;
            }
        }

        return n-count;

    }
};