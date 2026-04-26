class Solution {
public:
    int m, n;
    vector<vector<int>> visited;
    
    bool dfs(vector<vector<char>>& grid, int i, int j, int pi, int pj) {
        visited[i][j] = 1;
        
        int dirs[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
        
        for (auto &d : dirs) {
            int ni = i + d[0];
            int nj = j + d[1];
            
            if (ni < 0 || nj < 0 || ni >= m || nj >= n) continue;
            
            if (grid[ni][nj] != grid[i][j]) continue;
            
            // if not visited → go deeper
            if (!visited[ni][nj]) {
                if (dfs(grid, ni, nj, i, j)) return true;
            } 
            // if visited and NOT parent → cycle found
            else if (ni != pi || nj != pj) {
                return true;
            }
        }
        
        return false;
    }
    
    bool containsCycle(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        visited.assign(m, vector<int>(n, 0));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j]) {
                    if (dfs(grid, i, j, -1, -1)) {
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
};