class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        const vector<string> phone = {
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        vector<string> res;
        string path;

        function<void(int)> backtrack = [&](int i) {
            if (i == (int)digits.size()) {
                res.push_back(path);
                return;
            }
            for (char ch : phone[digits[i] - '0']) {
                path.push_back(ch);
                backtrack(i + 1);
                path.pop_back();
            }
        };

        backtrack(0);
        return res;
    }
};