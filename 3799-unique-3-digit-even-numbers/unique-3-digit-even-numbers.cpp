class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> result;
        unordered_map<int, int> freq;

        // Count frequency of each digit
        for (int d : digits) {
            freq[d]++;
        }

        // Iterate all 3-digit even numbers
        for (int num = 100; num <= 999; num += 2) {
            int a = num / 100;
            int b = (num / 10) % 10;
            int c = num % 10;

            unordered_map<int, int> temp = freq;
            if (--temp[a] >= 0 && --temp[b] >= 0 && --temp[c] >= 0) {
                result.push_back(num);
            }
        }
        return result.size();
    }
};