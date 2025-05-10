class Solution {
public:
    long long minSum(vector<int>& n1, vector<int>& n2) {
        long long s1 = 0, s2 = 0, b1 = 0, b2 = 0;
        for (auto& n : n1){
            s1 += max(1, n);
            b1 = b1 || !n;
        }
        for (auto& n : n2){
            s2 += max(1, n);
            b2 = b2 || !n;
        }
        if (s1 > s2){
            swap(s2, s1);
            swap(b1, b2);
        }
        return s1 == s2 || b1 ? s2 : -1; 
    }
};