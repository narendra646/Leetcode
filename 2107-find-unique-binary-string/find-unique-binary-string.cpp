class Solution {
public:
    int getDecimal(string &s)
    {
        long long ans=0;
        long long m=1;
        reverse(s.begin(),s.end());
        for(char c : s)
        {
            ans+=m*(c-'0');
            m*=2;
        }
        return ans;
    }

    string getBinary(int n,int len)
    {
        string binary = "";
        if(n == 0) binary = "0";
        while(n > 0) {
            binary = char('0' + (n % 2)) + binary;
            n = n / 2;
        }
        while(binary.size() < len)
        binary = "0" + binary;
        return binary;
    }
    string findDifferentBinaryString(vector<string>& nums) {
        int n=nums[0].size();
        int maxi=(1 << n) - 1;        
        set<int>st;
        for(int i=0;i<nums.size();i++)
        {
            int nm=getDecimal(nums[i]);
            st.insert(nm);
        }

        string ans;
        for(int i=0;i<=maxi;i++)
        {
            if(st.find(i)==st.end())
            {
                ans=getBinary(i,n);
                break;
            }
        }

        return ans;

    }
};