class Solution {
public:
    using ll = long long;
    using Edge = pair<int, int>; // {to, weight}

    int findMaxPathScore(vector<vector<int>>& edges,
                         vector<bool>& online,
                         ll k) {

        const int n = online.size();
        vector<vector<Edge>> graph(n);

        int lo = INT_MAX, hi = 0;

        for (const auto& e : edges) {
            const auto u = e[0];
            const auto v = e[1];
            const auto w = e[2];

            if (!online[u] || !online[v])
                continue;

            graph[u].emplace_back(v, w);
            lo = min(lo, w);
            hi = max(hi, w);
        }

        auto canReach = [&](int minWeight) -> bool {
            vector<ll> dist(n, LLONG_MAX);

            using State = pair<ll, int>; // {distance, node}
            priority_queue<State, vector<State>, greater<>> pq;

            dist[0] = 0;
            pq.emplace(0, 0);

            while (!pq.empty()) {
                const auto [d, u] = pq.top();
                pq.pop();

                if (d > dist[u])
                    continue;

                if (d > k)
                    return false;

                if (u == n - 1)
                    return true;

                for (const auto& [v, w] : graph[u]) {
                    if (w < minWeight)
                        continue;

                    const ll nd = d + w;
                    if (nd < dist[v]) {
                        dist[v] = nd;
                        pq.emplace(nd, v);
                    }
                }
            }

            return false;
        };

        if (!canReach(lo))
            return -1;

        while (lo <= hi) {
            const int mid = std::midpoint(lo, hi);

            if (canReach(mid))
                lo = mid + 1;
            else
                hi = mid - 1;
        }

        return hi;
    }
};