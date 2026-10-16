class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if (s.empty() || words.empty()) return res;
        int n = s.size(), m = words.size(), w = words[0].size();
        if (n < m * w) return res;

        unordered_map<string, int> need;
        for (auto& x : words) need[x]++;

        for (int off = 0; off < w; off++) {
            int left = off, count = 0;
            unordered_map<string, int> seen;
            for (int r = off; r + w <= n; r += w) {
                string word = s.substr(r, w);
                if (need.count(word)) {
                    seen[word]++;
                    count++;
                    while (seen[word] > need[word]) {
                        seen[s.substr(left, w)]--;
                        left += w;
                        count--;
                    }
                    if (count == m) {
                        res.push_back(left);
                        seen[s.substr(left, w)]--;
                        left += w;
                        count--;
                    }
                } else {
                    seen.clear();
                    count = 0;
                    left = r + w;
                }
            }
        }
        return res;
    }
};