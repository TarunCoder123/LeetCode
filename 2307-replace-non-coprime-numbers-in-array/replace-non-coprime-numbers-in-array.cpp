class Solution {
public:
    int GCD(int a, int b) {
        if (b == 0) return a;
        return GCD(b, a % b);
    }

    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<int> s;
        for (int num : nums) {
            int curr = num;
            while (!s.empty()) {
                int g = GCD(s.top(), curr);
                if (g > 1) {
                    curr = 1ll * s.top() * curr / g; // lcm
                    s.pop();
                } else {
                    break;
                }
            }
            s.push(curr);
        }

        vector<int> ans;
        while (!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
