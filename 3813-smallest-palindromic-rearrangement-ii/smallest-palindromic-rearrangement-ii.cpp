class Solution {
public:
    int binomCapped(int n, int r, int k) {
        if (r > n - r) r = n - r;
        long long res = 1;
        for (int i = 1; i <= r; i++) {
            res = res * (n - i + 1) / i;
            if (res >= k) return k;
        }
        return (int)res;
    }
    int findWays(int k, vector<int> &freq)
    {
        int total = 0;
        int ways = 1;
        for (int f : freq) {
            if (f == 0) continue;
            int addWays = binomCapped(total + f, f, k);
            long long tmp = (long long)ways * addWays;
            ways = (tmp >= k ? k : (int)tmp);
            total += f;
        }
        return ways;
    }
    string smallestPalindrome(string s, int k) 
    {
        int n=s.size(),len=n/2;
        vector<int>count(26,0);
        for(int i=0;i<len;i++)
           count[s[i]-'a']++;
        int i=0,j=n-1,c=0;
        while(i<j && c<26)
        {
            if(count[c]>0)
            {
                count[c]--;
                int ways=findWays(k,count);
                if(ways>=k)
                {
                    s[i]=s[j]=(c+'a');
                    i++;j--;
                    c=0;
                }
                else
                {
                    k-=ways;
                    count[c]++;
                    c++;
                }
            }
            else
               c++;
        }  
        return c>25?"":s; 
    }
};