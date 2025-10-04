class Solution {
public:
    bool isPossible(vector<int>& target) {
      
      priority_queue<long long>pq;
      long long sum=0;
      for(int i=0;i<target.size();i++)
      {
         pq.push(target[i]);
         sum+=target[i];
      }

      long long maxel,remsum,el;
      while(pq.top()!=1)
      {
         maxel=pq.top();
         pq.pop();
         
         remsum=sum-maxel;
         if(remsum<=0 || remsum>maxel)
         return 0;

         el=maxel%remsum;
         if(el==0)
         {
            if(remsum!=1)
            return 0;
            else
            return 1;
         }

         sum=el+remsum;

         pq.push(el);

      }

      return 1;
     
    }
};