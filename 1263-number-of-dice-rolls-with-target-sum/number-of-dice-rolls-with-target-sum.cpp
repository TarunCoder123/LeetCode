class Solution {
public:
    int dp[35][1005];
    int K;
    const int MOD=1e9+7;
    int solve(int i,int target){
      if(target==0 && i==0)return 1;  
      if(i<0)return 0;
      if(target<0)return 0;
      if(dp[i][target]!=-1)return dp[i][target];
      int ans=0;
      for(int j=1;j<=K;j++){
        ans=(ans+solve(i-1,target-j))%MOD;
      }
      return dp[i][target]=ans%MOD;
    }
    int numRollsToTarget(int n, int k, int target) {
    K=k;
    memset(dp,-1,sizeof(dp));
    return solve(n,target);  
    } 
};