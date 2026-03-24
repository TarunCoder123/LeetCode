class Solution {
public:
    long long mod = 1000000007;

    long long power(long long a, long long n) {
        long long res = 1;
        while (n > 0) {
            if (n % 2) res = (res * a) % mod;
            a = (a * a) % mod;
            n /= 2;
        }
        return res;
    }

    int monkeyMove(int n) {
        return (int)((power(2, n) - 2 + mod) % mod);
    }
};