class Solution {
public:
   int n;
    void right_min(vector<int>&r_min,vector<int>& heights)
    {
        stack<int>s;
        for(int i=0;i<n;i++)
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
        for(int i=n-1;i>=0;i--)
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
    int largestRectangleArea(vector<int>& heights) {
        n=heights.size();
        vector<int>r_min(n,n);
        vector<int>l_min(n,-1);
        
        right_min(r_min,heights);
        left_min(l_min,heights);

        int ans=INT_MIN;
        for(int i=0;i<n;i++)
        {
            ans=max(ans,(r_min[i]-l_min[i]-1)*heights[i]);
        }

        return ans;

    }
};