class Solution {
    int dfs(int full, int cols, int ld, int rd) {
        if (cols == full) return 1;
        int avail = full & ~(cols | ld | rd), cnt = 0;
        while (avail) {
            int bit = avail & -avail;
            avail -= bit;
            cnt += dfs(full, cols | bit, ((ld | bit) << 1) & full, (rd | bit) >> 1);
        }
        return cnt;
    }
public:
    int totalNQueens(int n) {
        return dfs((1 << n) - 1, 0, 0, 0);
    }
};