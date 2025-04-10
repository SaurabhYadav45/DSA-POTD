class Solution {
public:
    long long solve(string str, string suffix, int limit){
        if(str.length() < suffix.length())return 0;

        string trailString = str.substr(str.length()-suffix.length());
        int remLength = str.length()-suffix.length();

        long long count = 0;
        for(int i=0; i<remLength; i++){
            int digit = str[i]-'0';
            if(digit <= limit){
                count += digit*pow(limit+1, remLength-i-1);
            }
            else{
                count += pow(limit+1, remLength-i);
                return count;
            }
        }
        if(trailString >= suffix){
            count++;
        }
        return count;
    }
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        string startStr = to_string(start-1);
        string finishStr = to_string(finish);

        return solve(finishStr, s, limit)-solve(startStr, s, limit);
    }
};