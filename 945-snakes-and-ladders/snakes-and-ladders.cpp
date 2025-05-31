class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size(), dest = (n * n) - 1, steps = 0;
        // treat board as top to bottom and left to right
        reverse(board.begin(), board.end()); // flip x-axis
        for (int i = 0 ; i < n ; ++i) if (i & 1) reverse(board[i].begin(), board[i].end()); // flip alternate y-axis
        // make it 0-based
        for (auto &row : board) for (int &cell : row) if (cell > 0) cell--;

        vector<bool> vis(n * n, 0);
        queue<int> q;
        q.push(0); vis[0] = 1;
        while (steps <= dest && !q.empty()) {
            int nn = q.size();
            while (nn--) {
                int cur = q.front(); q.pop();
                if (cur == dest) return steps;
                for (int step = 1 ; step <= 6 ; step++) {
                    int nxt = min(dest, cur + step);
                    if (vis[nxt]) continue;
                    vis[nxt] = 1;
                    int nr = nxt / n, nc = nxt % n;
                    if (board[nr][nc] >= 0) nxt = board[nr][nc];
                    q.push(nxt);
                }
            }
            steps++;
        }
        return -1;
    }
};