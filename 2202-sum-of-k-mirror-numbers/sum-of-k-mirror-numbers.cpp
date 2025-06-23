class Solution {
public:
    bool checkPalindrome(string s){
        long long i=0;
        long long j = s.length()-1;
        while(i < j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    string convertToBaseK(long long num, int k){
        if(num == 0){
            return "0";
        }
        string result = "";
        while(num > 0){
            result += to_string(num % k);
            num /= k;
        }
        return result;
    }
    long long kMirror(int k, int n) {
        long long result = 0;
        long long L = 1;

        while(n > 0){
            long long l = (L+1)/2;
            long long start = pow(10, l-1);
            long long end = pow(10, l)-1;

            for(long long num = start; num <= end; num++){
                string half = to_string(num);
                string next_half = half;
                reverse(next_half.begin(), next_half.end());
                string pal = "";
                if(L % 2 == 0){
                    pal = half + next_half;
                }
                else{
                    pal = half + next_half.substr(1);
                }

                long long pal_num = stoll(pal);
                string baseK_num = convertToBaseK(pal_num, k);
                if(checkPalindrome(baseK_num)){
                    result += pal_num;
                    n--;
                    if(n == 0){
                        break;
                    }
                }
            }
            L++;
        }
        return result;
    }
};