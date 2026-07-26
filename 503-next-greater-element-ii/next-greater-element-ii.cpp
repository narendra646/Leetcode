class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& arr) {
        int n=arr.size();
        stack<int>s;
        vector<int>v(n,-1);
        int j=0;
        while(j<2*n)
        {
            int i=j%n;
            if(s.size()==0)
            s.push(i);
            else
            {
                if(arr[s.top()]>=arr[i])
                s.push(i);
                else
                {
                    while(s.size() && arr[i]>arr[s.top()])
                    {
                        v[s.top()]=arr[i];
                        s.pop();
                    }
                    
                    s.push(i);
                }
            }
            
            j++;
        } 
        return v;
    }
};