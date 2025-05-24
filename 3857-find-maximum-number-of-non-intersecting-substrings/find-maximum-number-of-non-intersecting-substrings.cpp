class Solution {
public:
    int maxSubstrings(string word) {
        unordered_map<char,int> m;
        int ans=0;
        
        for(int i=0;i<word.size();i++)
            {
                if(m.find(word[i])!=m.end())
                {
                    if((i-m[word[i]]+1)>=4)
                    {
                        ans++;
                    m.clear();
                    }
                }
                else
                {
                    m[word[i]]=i;
                }
                
            }
        return ans;
        
        
    }
};