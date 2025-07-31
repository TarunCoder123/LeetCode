class Solution {
public:
    int subarrayBitwiseORs(std::vector<int>& A) {
        std::unordered_set<int> ans;
        std::set<int> cur;
        cur.insert(0);
        
        for (int x : A) {
            std::set<int> cur2;
            for (int y : cur) {
                cur2.insert(x | y);
            }
            cur2.insert(x);
            cur = cur2;

            for (int val : cur) {
                ans.insert(val);
            }
        }

        return ans.size();
    }
};
