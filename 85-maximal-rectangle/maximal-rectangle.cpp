class Solution {
public:
    int n,m;
    void right_min(vector<int>&r_min,vector<int>& heights)
    {
        stack<int>s;
        for(int i=0;i<m;i++)
        {
            if(s.empty())
            s.push(i);
            else
            {
                while(!s.empty() && heights[i]<heights[s.top()])
                {
                    r_min[s.top()]=i;
                    s.pop();
                }

                s.push(i);
            }
        }
    }

    void left_min(vector<int>&l_min,vector<int>& heights)
    {
        stack<int>s;
        for(int i=m-1;i>=0;i--)
        {
            if(s.empty())
            s.push(i);
            else
            {
                while(!s.empty() && heights[i]<heights[s.top()])
                {
                    l_min[s.top()]=i;
                    s.pop();
                }

                s.push(i);
            }
        }
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        n=matrix.size(),m=matrix[0].size();
        vector<int>v(m,0);
        int  ans=INT_MIN;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]=='0')
                v[j]=0;
                else
                v[j]+=1;
            }
            vector<int>r_min(m,m);
            vector<int>l_min(m,-1);

            right_min(r_min,v);
            left_min(l_min,v);
            for(int k=0;k<m;k++)
            {
                ans=max(ans,(r_min[k]-l_min[k]-1)*v[k]);
            }
        }

        return ans;
    }
};