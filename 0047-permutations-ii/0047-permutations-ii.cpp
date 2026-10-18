class Solution {
    vector<vector<int>> res;
    vector<int> cur;
    vector<bool> used;
    void dfs(vector<int>& a) {
        if (cur.size() == a.size()) { res.push_back(cur); return; }
        for (int i = 0; i < (int)a.size(); i++) {
            if (used[i]) continue;
            if (i > 0 && a[i] == a[i - 1] && !used[i - 1]) continue;
            used[i] = true;
            cur.push_back(a[i]);
            dfs(a);
            cur.pop_back();
            used[i] = false;
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        res.clear(); cur.clear();
        sort(nums.begin(), nums.end());
        used.assign(nums.size(), false);
        dfs(nums);
        return res;
    }
};