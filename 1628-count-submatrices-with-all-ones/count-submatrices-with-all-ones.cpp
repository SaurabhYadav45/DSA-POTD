class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int result = 0;
        
        for(int start=0; start<m; start++){
            vector<int>temp(n, 1);
            for(int end=start; end<m; end++){
                for(int i=0; i<n; i++){
                    temp[i] = (temp[i] & mat[end][i]);
                }
                int count = 0;
                for(int i=0; i<n; i++){
                    if(temp[i] == 1){
                        count++;
                    }
                    else{
                        count = 0;
                    }
                    result += count;
                }
            }
        }
        return result;
    }
};