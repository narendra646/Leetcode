class Solution {
public:
    int subarraySum(vector<int>& A, int B) {    
    unordered_map<int,int>mp;
    mp[0]=1;
    int pref_sum=0,count=0;
    for(int i=0;i<A.size();i++)
    {
        pref_sum+=A[i];
        int removal=pref_sum-B;
        if(mp[removal])
        count+=mp[removal];
        
        mp[pref_sum]++;
    }
    
    return count;
    }
};