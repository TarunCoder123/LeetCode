class Solution {
public:
    int dp[110][110];
    int f(int i,int j,int m,int n){
        if(i<0 || j<0)return 0;
        if(i==0 && j==0)return 1;
        if(dp[i][j]!=-1)return dp[i][j];
        int val1=f(i-1,j,m,n);
        int val2=f(i,j-1,m,n);
        return dp[i][j]=val1+val2;
    }
    int uniquePaths(int m, int n) {
      memset(dp,-1,sizeof dp);
      return f(m-1,n-1,m,n);  
    }
};