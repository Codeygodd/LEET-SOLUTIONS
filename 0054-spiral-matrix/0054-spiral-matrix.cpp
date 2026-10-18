class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int top = 0, bot = matrix.size() - 1, left = 0, right = matrix[0].size() - 1;
        while (top <= bot && left <= right) {
            for (int j = left; j <= right; j++) res.push_back(matrix[top][j]);
            top++;
            for (int i = top; i <= bot; i++) res.push_back(matrix[i][right]);
            right--;
            if (top <= bot) {
                for (int j = right; j >= left; j--) res.push_back(matrix[bot][j]);
                bot--;
            }
            if (left <= right) {
                for (int i = bot; i >= top; i--) res.push_back(matrix[i][left]);
                left++;
            }
        }
        return res;
    }
};