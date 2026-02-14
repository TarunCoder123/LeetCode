class Solution {
public:
    double memo[101][101];
    bool visited[101][101];

    double solve(int r, int c, int poured) {
        
        // invalid position
        if (c < 0 || c > r) return 0.0;
        
        // top glass
        if (r == 0 && c == 0) return poured;
        
        if (visited[r][c]) 
            return memo[r][c];
        
        visited[r][c] = true;

        double leftParent = solve(r - 1, c - 1, poured);
        double rightParent = solve(r - 1, c, poured);

        double overflowFromLeft = max(0.0, (leftParent - 1.0) / 2.0);
        double overflowFromRight = max(0.0, (rightParent - 1.0) / 2.0);

        memo[r][c] = overflowFromLeft + overflowFromRight;

        return memo[r][c];
    }

    double champagneTower(int poured, int query_row, int query_glass) {
        
        memset(visited, false, sizeof(visited));
        
        double ans = solve(query_row, query_glass, poured);
        
        return min(1.0, ans);
    }
};
