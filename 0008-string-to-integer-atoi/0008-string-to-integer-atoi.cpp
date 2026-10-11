class Solution {
public:
    int myAtoi(string s) {
        int i = 0, sign = 1;
        long long num = 0;

        while (i < s.size() && s[i] == ' ')
            i++;

        if (i < s.size() && (s[i] == '-' || s[i] == '+')) {
            if (s[i] == '-')
                sign = -1;
            i++;
        }

        while (i < s.size() && s[i] >= '0' && s[i] <= '9') {
            num = num * 10 + (s[i] - '0');

            if (sign == 1 && num > 2147483647LL)
                return 2147483647;

            if (sign == -1 && num > 2147483648LL)
                return -2147483648LL;

            i++;
        }

        return (int)(sign * num);
    }
};