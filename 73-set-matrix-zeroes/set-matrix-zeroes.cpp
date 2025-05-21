class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        int m =matrix.size();
        int n = matrix[0].size();

        // x and y used as marker as if 0 present in first row and first col
        int x =1;
        int y =1;
        for(int j=0;j<n;j++)
        {
            if(matrix[0][j]==0)x=0;
            
        }
        
        for(int i=0;i<m;i++)
        {
            if(matrix[i][0]==0)y=0;
        }
       
        // Checking if zeroes present in part of matrix
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(matrix[i][j]==0)
                {
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        
        
         for(int j=1;j<n;j++)
        {
           if(matrix[0][j]==0)
           {
               for(int i=1;i<m;i++)
                   matrix[i][j]=0;
           }
        }
        
        for(int i=1;i<m;i++)
        {
            if(matrix[i][0]==0)
            {
                for(int j=0;j<n;j++)
                    matrix[i][j]=0;
            }
        }
        
        if(y==0)
        {
            for(int i=0;i<m;i++)
            {
                matrix[i][0]=0;
            }
        }
        
         if(x==0)
        {      
             for(int j=0;j<n;j++)
            matrix[0][j]=0;
        
        }
//         int row =matrix.size();
//         int col = matrix[0].size();
//         vector<int>x,y;
//         for(int i=0; i<row; i++){
//             for(int j=0; j<col; j++){
//                 if(matrix[i][j] == 0){
//                     x.push_back(i);
//                     y.push_back(j);
//                 }
//             }
//         }

//         // delete row;
//         for(int i=0; i<x.size(); i++){
//             int index = x[i];
//             for(int j=0; j<col; j++){
//                 matrix[index][j] = 0;
//             }
//         }
//         // delete col
//         for(int i=0; i<y.size(); i++){
//             int index = y[i];
//             for(int j=0; j<row; j++){
//                 matrix[j][index] = 0;
//             }
//         }
    }
};
