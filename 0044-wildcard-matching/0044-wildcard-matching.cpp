class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        int i = 0, j = 0, star = -1, mark = 0;
        while (i < n) {
            if (j < m && (p[j] == '?' || p[j] == s[i])) { i++; j++; }
            else if (j < m && p[j] == '*') { star = j++; mark = i; }
            else if (star != -1) { j = star + 1; i = ++mark; }
            else return false;
        }
        while (j < m && p[j] == '*') j++;
        return j == m;
    }
};