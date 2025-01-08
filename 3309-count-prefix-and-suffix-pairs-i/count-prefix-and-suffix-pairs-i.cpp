class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int count=0;
        for(int i=0;i<words.size()-1;i++)
        {
            for(int j=i+1;j<words.size();j++)
            {
                if(words[i].size()<=words[j].size())
                {
                    if(words[i]==words[j])
                    count++;
                    else
                    {
                        // string str1=words[j].substr(0,words[i].size());
                        // string str2=words[j].substr(words[j].size()-words[i].size(),words[i].size());
                        // if(str1==str2)
                        // count++;
                        string str1=words[i];
                        string str2=words[j];
                        if (str2.find(str1) == 0 && str2.rfind(str1) == str2.size() - str1.size()) 
                        count++;
                    }
                }
            }
        }

        return count;
    }
};