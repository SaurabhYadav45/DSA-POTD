class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;

                int x1 = points[i][0], y1 = points[i][1]; // candidate A
                int x2 = points[j][0], y2 = points[j][1]; // candidate B

                // A must be upper-left of B
                if (x1 > x2 || y1 < y2) continue;

                bool valid = true;
                for (int k = 0; k < n; k++) {
                    if (k == i || k == j) continue;
                    int x = points[k][0], y = points[k][1];

                    // check if inside or on the border of rectangle [x1,y1] - [x2,y2]
                    if (x1 <= x && x <= x2 && y2 <= y && y <= y1) {
                        valid = false;
                        break;
                    }
                }
                if (valid) count++;
            }
        }
        return count;
    }
};
