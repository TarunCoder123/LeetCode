class Solution {
public:
    int dp[105][105];
    int solve(int i,int j,vector<vector<int>>& obstacleGrid){
        if(i==0 && j==0)return 1;
        if(i<0 || j<0 || obstacleGrid[i][j]==1)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int path1=solve(i-1,j,obstacleGrid);
        int path2=solve(i,j-1,obstacleGrid);
        return dp[i][j]=path1+path2;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        if(obstacleGrid[0][0]==1)return 0;
        memset(dp,-1,sizeof(dp));
        return solve(m-1,n-1,obstacleGrid);
    }
};