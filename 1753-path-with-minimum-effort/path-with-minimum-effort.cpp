class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size(), cols = heights[0].size();
        vector<vector<int>> dist(rows, vector<int>(cols, INT_MAX));

        priority_queue<pair<int, pair<int, int>>, 
                       vector<pair<int, pair<int, int>>>, greater<>> pq;
        pq.emplace(0, make_pair(0, 0));
        dist[0][0] = 0;

        vector<pair<int, int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        while (!pq.empty()) {
            auto [effort, cell] = pq.top();
            pq.pop();
            int x = cell.first, y = cell.second;

            if (x == rows - 1 && y == cols - 1) {
                return effort;
            }

            for (auto [dx, dy] : directions) {
                int newX = x + dx, newY = y + dy;
                if (newX >= 0 && newY >= 0 && newX < rows && newY < cols) {
                    int currEffort = abs(heights[x][y] - heights[newX][newY]);
                    int maxEffort = max(effort, currEffort);
                    if (maxEffort < dist[newX][newY]) {
                        dist[newX][newY] = maxEffort;
                        pq.emplace(maxEffort, make_pair(newX, newY));
                    }
                }
            }
        }

        return 0;
    }
};