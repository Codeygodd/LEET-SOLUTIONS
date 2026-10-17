class Solution {
    vector<vector<int>> res;
    vector<int> cur;
    void dfs(vector<int>& c, int start, int rem) {
        if (rem == 0) { res.push_back(cur); return; }
        for (int i = start; i < (int)c.size() && c[i] <= rem; i++) {
            cur.push_back(c[i]);
            dfs(c, i, rem - c[i]);
            cur.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        res.clear(); cur.clear();
        sort(candidates.begin(), candidates.end());
        dfs(candidates, 0, target);
        return res;
    }
};