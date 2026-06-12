class Solution {
public:
    static const long long MOD = 1e9 + 7;

    int maxDepth = 0;

    void dfs(int node, int parent, int depth,
             vector<vector<int>>& adj) {

        maxDepth = max(maxDepth, depth);

        for (int nxt : adj[node]) {
            if (nxt == parent) continue;

            dfs(nxt, node, depth + 1, adj);
        }
    }

    long long modPow(long long a, long long b) {
        long long res = 1;

        while (b) {
            if (b & 1)
                res = (res * a) % MOD;

            a = (a * a) % MOD;
            b >>= 1;
        }

        return res;
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {

        int n = edges.size() + 1;

        vector<vector<int>> adj(n + 1);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        dfs(1, 0, 0, adj);

        if (maxDepth == 0)
            return 0;

        return modPow(2, maxDepth - 1);
    }
};