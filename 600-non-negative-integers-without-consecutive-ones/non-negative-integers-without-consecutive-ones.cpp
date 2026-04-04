class Solution {
public:
    int dp[32][2][3][2];

    int digitdp(int pos, int tight, int prev, int leading_zero, string &num)
    {
        if(pos == num.size())
            return 1;

        if(dp[pos][tight][prev][leading_zero] != -1)
            return dp[pos][tight][prev][leading_zero];

        int limit = tight ? num[pos] - '0' : 1;
        int ans = 0;

        for(int d = 0; d <= limit; d++)
        {
            int new_tight = tight && (d == limit);
            int new_leading_zero = leading_zero && (d == 0);

            if(!new_leading_zero && prev == 1 && d == 1)
                continue;

            int new_prev = prev;
            if(!new_leading_zero)
                new_prev = d;

            ans += digitdp(pos + 1, new_tight, new_prev, new_leading_zero, num);
        }

        return dp[pos][tight][prev][leading_zero] = ans;
    }

    int findIntegers(int n) {
        string num = "";
        while(n > 0){
            num.push_back((n & 1) + '0');
            n >>= 1;
        }
        reverse(num.begin(), num.end());

        memset(dp, -1, sizeof(dp));
        return digitdp(0, 1, 2, 1, num); // prev=2 means no previous digit
    }
};