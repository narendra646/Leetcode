class Solution {
public:
    int count_0(queue<int>que)
    {
        int c_0=0;
        while(!que.empty())
        {
            if(que.front()==0)
            c_0++;

            que.pop();
        }

        return c_0;
    }

    int count_1(queue<int>que)
    {
        int c_1=0;
        while(!que.empty())
        {
            if(que.front()==1)
            c_1++;

            que.pop();
        }

        return c_1;
    }


    int countStudents(vector<int>& students, vector<int>& sandwiches) {
       reverse(sandwiches.begin(),sandwiches.end());
       stack<int>s;
       for(int i=0;i<sandwiches.size();i++)
       s.push(sandwiches[i]);
       queue<int>q;
       for(int i=0;i<students.size();i++)
       q.push(students[i]);

       while(!q.empty() && !s.empty())
       {
         if(q.front()==s.top())
         {
            q.pop();
            s.pop();
         }
         else if(q.front()!=s.top() && ((count_0(q)==0 && s.top()==0)|| (count_1(q)==0 && s.top()==1)))
         break;
         else if(q.front()!=s.top())
         {
            int a=q.front();
            q.pop();
            q.push(a);
         }
       }
      
      return q.size();


    }
};