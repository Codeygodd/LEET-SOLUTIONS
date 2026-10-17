class Solution {
    vector<vector<int>> res;
    vector<int> cur;
    void dfs(vector<int>& c, int start, int rem) {
        if (rem == 0) { res.push_back(cur); return; }
        for (int i = start; i < (int)c.size(); i++) {
            if (c[i] > rem) break;
            if (i > start && c[i] == c[i - 1]) continue;
            cur.push_back(c[i]);
            dfs(c, i + 1, rem - c[i]);
            cur.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        res.clear(); cur.clear();
        sort(candidates.begin(), candidates.end());
        dfs(candidates, 0, target);
        return res;
    }
};