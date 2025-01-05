class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n=s.size();
        vector<int>diff(n,0);
        for(int i=0;i<shifts.size();i++){
            int start=shifts[i][0],end=shifts[i][1];
            int d=shifts[i][2];
            if(d==1)
            {
                diff[start]+=1;
                if(end+1<n)
                diff[end+1]-=1;
            }
            else
            {
                diff[start]-=1;
                if(end+1<n)
                diff[end+1]+=1;
            }
    }
 int shift=0;
 string result(n,' ');
 for(int i=0;i<s.size();i++){
      shift=(shift+diff[i])%26;

      if(shift<0)
      shift+=26;

      result[i]='a'+(s[i]-'a'+shift)%26;

 }

 return result;


    }
};