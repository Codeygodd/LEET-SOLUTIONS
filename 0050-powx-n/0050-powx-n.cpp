class Solution {
public:
    double myPow(double x, int n) {
        long long e = n;
        bool neg = e < 0;
        if (neg) e = -e;
        long double r = 1, b = x;
        while (e) {
            if (e & 1) r *= b;
            b *= b;
            e >>= 1;
        }
        return neg ? (double)(1.0L / r) : (double)r;
    }
};