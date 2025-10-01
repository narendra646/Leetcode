class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int cap=capacity;
        int ans=0;
        for(int i=0;i<plants.size();i++)
        {
            if(cap>=plants[i])
            {
                ans++;
                cap-=plants[i];
            }
            else
            {
                ans+=i+i+1;
                cap=capacity-plants[i];
            }
        }

        return ans;
    }
};