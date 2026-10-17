class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        int n = num1.size(), m = num2.size();
        vector<int> p(n + m, 0);
        for (int i = n - 1; i >= 0; i--)
            for (int j = m - 1; j >= 0; j--) {
                int sum = (num1[i] - '0') * (num2[j] - '0') + p[i + j + 1];
                p[i + j + 1] = sum % 10;
                p[i + j] += sum / 10;
            }
        string res;
        int idx = 0;
        while (idx < n + m && p[idx] == 0) idx++;
        for (; idx < n + m; idx++) res += char('0' + p[idx]);
        return res;
    }
};