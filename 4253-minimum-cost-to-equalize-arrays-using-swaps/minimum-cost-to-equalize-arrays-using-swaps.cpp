class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        unordered_map<int,int>m1,m2;
        for(int i=0;i<n;i++)
        {
            m1[nums1[i]]++;
            m2[nums2[i]]++;
        }

        int count=0;
        for(auto it:m1)
        {
            if(m2.find(it.first)!=m2.end())
            {
                count+=abs(m2[it.first]-it.second)/2;
                if(abs(m2[it.first]-it.second)%2==1)
                return -1;

                m2.erase(it.first);
            }
            else
            {
                count+=it.second/2;
                if(it.second%2==1)
                return -1;
            }
        }


        for(auto it:m2)
        {
            if(m1.find(it.first)!=m1.end())
            {
                count+=abs(m1[it.first]-it.second)/2;
                if(abs(m1[it.first]-it.second)%2==1)
                return -1;
            }
            else
            {
                count+=it.second/2;
                if(it.second%2==1)
                return -1;
            }
        }
        return count/2;
     
    }
};