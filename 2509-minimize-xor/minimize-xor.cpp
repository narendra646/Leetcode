class Solution {
public:

     bool isSet(int x, int bit)
      {
         return x & (1 << bit);
      }

    void setBit(int &x, int bit)
     {
         x |= (1 << bit); 
     }

    void unsetBit(int &x, int bit)
     {
         x &= ~(1 << bit);
     }

    int minimizeXor(int num1, int num2) {
        int ans=num1;
        int req_bit= __builtin_popcount(num2);
        int set_bit=__builtin_popcount(ans);

        int curr_bit=0;

        while(set_bit<req_bit)
        {
            if(!isSet(ans,curr_bit))
            {
                setBit(ans,curr_bit);
                set_bit++;
            }
            curr_bit++;
        }

        while(set_bit>req_bit)
        {
            if(isSet(ans,curr_bit))
            {
                unsetBit(ans,curr_bit);
                set_bit--;
            }
            curr_bit++;
        }

        return ans;

    }
};