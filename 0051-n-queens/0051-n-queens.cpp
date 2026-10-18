class Solution {
    vector<vector<string>> res;
    vector<string> board;
    vector<bool> col, d1, d2;
    int n;
    void dfs(int r) {
        if (r == n) { res.push_back(board); return; }
        for (int c = 0; c < n; c++) {
            if (col[c] || d1[r + c] || d2[r - c + n - 1]) continue;
            board[r][c] = 'Q';
            col[c] = d1[r + c] = d2[r - c + n - 1] = true;
            dfs(r + 1);
            board[r][c] = '.';
            col[c] = d1[r + c] = d2[r - c + n - 1] = false;
        }
    }
public:
    vector<vector<string>> solveNQueens(int N) {
        n = N;
        res.clear();
        board.assign(n, string(n, '.'));
        col.assign(n, false);
        d1.assign(2 * n, false);
        d2.assign(2 * n, false);
        dfs(0);
        return res;
    }
};