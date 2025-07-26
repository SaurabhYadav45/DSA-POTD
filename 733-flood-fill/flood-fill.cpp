class Solution {
public:
    int m;
    int n;
    vector<vector<int>>directions{{0,1}, {0,-1}, {1, 0}, {-1,0}};
    void dfs(vector<vector<int>>& image, int sr, int sc, int color, int initialPixel){
        if(sr < 0 || sr >= m || sc < 0 || sc >= n){
            return ;
        }
        if(image[sr][sc] != initialPixel) return;

        image[sr][sc] = color;

        for(auto& dir : directions){
            int i = sr + dir[0];
            int j = sc + dir[1];
            dfs(image, i, j, color, initialPixel);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        m = image.size();
        n = image[0].size();
        int initialPixel = image[sr][sc];

        if(initialPixel != color)
            dfs(image, sr, sc, color, initialPixel);

        return image;
    }
};