class Solution {
public:
    int n;
    int maxScore;
    void solve(int i, int currScore, vector<string>& words,  vector<int>& freq,  vector<int>& score){
        //Base case
        if(i >= n){
            maxScore = max(maxScore, currScore);
            return;
        }

        // Can we take the current word
        int j = 0;
        int tempScore = 0;
        vector<int>tempFreq = freq;
        string word = words[i];
        while( j < word.length()){
            char ch = word[j];
            tempScore += score[ch-'a'];
            tempFreq[ch-'a']--;
            if(tempFreq[ch-'a'] < 0){
                break;
            }
            j++;
        }

        // Take 
        if(j == word.length()){
            currScore += tempScore;
            solve(i+1, currScore, words, tempFreq, score);
            currScore -= tempScore;  // Backtrack;
        }

        // skip
        solve(i+1, currScore, words, freq, score);
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        n = words.size();
        maxScore = INT_MIN;
        vector<int>freq(26, 0);
        for(char&ch : letters){
            freq[ch-'a']++;
        }

        solve(0, 0, words, freq, score);
        return maxScore;
    }
};