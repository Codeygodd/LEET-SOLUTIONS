class Solution {
    vector<vector<int>> res;
    void dfs(vector<int>& a, int start) {
        if (start == (int)a.size()) { res.push_back(a); return; }
        for (int i = start; i < (int)a.size(); i++) {
            swap(a[start], a[i]);
            dfs(a, start + 1);
            swap(a[start], a[i]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        res.clear();
        dfs(nums, 0);
        return res;
    }
};