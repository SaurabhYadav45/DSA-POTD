class Solution {
public:
    void solve(int currNum, int n, vector<int>&result){
        if(currNum > n){
            return;
        }

        result.push_back(currNum);
        for(int append=0; append<=9; append++){
            int newNum = (currNum*10) + append;
            if(newNum <= n){
                solve(newNum, n, result);
            }
            
        }
    }
    vector<int> lexicalOrder(int n) {
        // vector<string>temp(n);
        // for(int i=0; i<n; i++){
        //     temp[i] = to_string(i+1); 
        // }

        // sort(temp.begin(), temp.end());
        // vector<int>result(n);
        // for(int i=0; i<n;i++){
        //     result[i] = stoi(temp[i]);
        // }
        // return result;

        // Using Recursion
        vector<int>result;
        for(int startNum=1; startNum <=9; startNum++){
            solve(startNum, n, result);
        }
        return result;
    }
};