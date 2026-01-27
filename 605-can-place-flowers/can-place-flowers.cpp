class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int s=flowerbed.size();
        int i=0;
        if(s==1)
        {
            if(flowerbed[0]==0)
            n--;
        }
        else
     {
        while(i<s && n>0)
        {
            if(flowerbed[i]==0)
            {
                if(i==0 && flowerbed[i+1]==0)
                {
                    flowerbed[i]=1;
                    n--; 
                }
                else if(i==s-1 && flowerbed[i-1]==0)
                {
                    flowerbed[i]=1;
                    n--; 
                }
                else if(i-1>0 && flowerbed[i-1]==0 && i+1<s && flowerbed[i+1]==0)
                {
                    flowerbed[i]=1;
                    n--;
                }
            }
            i++;
        }
    }

        if(n>0)
        return false;

        return true;

    }
};