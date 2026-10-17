class Solution {
    int row[9], col[9], box[9];
    bool dfs(vector<vector<char>>& b, int pos) {
        while (pos < 81 && b[pos / 9][pos % 9] != '.') pos++;
        if (pos == 81) return true;
        int i = pos / 9, j = pos % 9, k = i / 3 * 3 + j / 3;
        int used = row[i] | col[j] | box[k];
        for (int d = 0; d < 9; d++) {
            int m = 1 << d;
            if (used & m) continue;
            b[i][j] = '1' + d;
            row[i] |= m; col[j] |= m; box[k] |= m;
            if (dfs(b, pos + 1)) return true;
            row[i] &= ~m; col[j] &= ~m; box[k] &= ~m;
            b[i][j] = '.';
        }
        return false;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        memset(row, 0, sizeof(row));
        memset(col, 0, sizeof(col));
        memset(box, 0, sizeof(box));
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                if (board[i][j] != '.') {
                    int m = 1 << (board[i][j] - '1');
                    row[i] |= m; col[j] |= m; box[i / 3 * 3 + j / 3] |= m;
                }
        dfs(board, 0);
    }
};