class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9] = {}, col[9] = {}, box[9] = {};
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;
                int b = 1 << (board[i][j] - '1');
                int k = i / 3 * 3 + j / 3;
                if ((row[i] & b) || (col[j] & b) || (box[k] & b)) return false;
                row[i] |= b; col[j] |= b; box[k] |= b;
            }
        return true;
    }
};