class Solution {
public:
    int minJumps(vector<int>& arr) {

        int n = arr.size();

        if (n == 1) return 0;

        unordered_map<int, vector<int>> m;

        for (int i = 0; i < n; i++) {
            m[arr[i]].push_back(i);
        }

        vector<bool> vis(n, false);

        queue<pair<int,int>> q;

        q.push({0, 0});

        vis[0] = true;

        while (!q.empty()) {

            auto [idx, jumps] = q.front();
            q.pop();

            if (idx == n - 1) return jumps;

            // idx + 1
            if (idx + 1 < n && !vis[idx + 1]) {
                vis[idx + 1] = true;
                q.push({idx + 1, jumps + 1});
            }

            // idx - 1
            if (idx - 1 >= 0 && !vis[idx - 1]) {
                vis[idx - 1] = true;
                q.push({idx - 1, jumps + 1});
            }

            // same value jumps
            if (m.count(arr[idx])) {

                for (int next : m[arr[idx]]) {

                    if (!vis[next]) {
                        vis[next] = true;
                        q.push({next, jumps + 1});
                    }
                }

                // IMPORTANT OPTIMIZATION
                m.erase(arr[idx]);
            }
        }

        return -1;
    }
};