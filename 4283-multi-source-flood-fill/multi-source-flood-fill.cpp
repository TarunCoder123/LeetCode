class Solution {
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
      vector<vector<int>> grid(n, vector<int>(m, 0));
    vector<vector<int>> time(n, vector<int>(m, INT_MAX));

    queue<pair<int,int>> q;

    // init
    for (auto &s : sources) {
        int r = s[0], c = s[1], color = s[2];
        grid[r][c] = color;
        time[r][c] = 0;
        q.push({r,c});
    }

    vector<pair<int,int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
    int t = 0;

    while (!q.empty()) {
        int sz = q.size();

        // store candidates for next layer
        map<pair<int,int>, int> next; // (r,c) -> max color

        while (sz--) {
            auto [r,c] = q.front(); q.pop();
            int color = grid[r][c];

            for (auto &[dr,dc]: dirs) {
                int nr = r + dr, nc = c + dc;

                if (nr<0 || nc<0 || nr>=n || nc>=m) continue;

                if (time[nr][nc] < t+1) continue;

                // collect best color for this cell at time t+1
                next[{nr,nc}] = max(next[{nr,nc}], color);
            }
        }

        // apply updates
        for (auto &[cell, color] : next) {
            int r = cell.first, c = cell.second;

            if (time[r][c] == INT_MAX) {
                time[r][c] = t+1;
                grid[r][c] = color;
                q.push({r,c});
            }
        }

        t++;
    }

    return grid;  
    }
};