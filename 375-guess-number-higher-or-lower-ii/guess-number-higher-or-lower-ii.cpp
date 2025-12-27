class Solution {
public:
    int dp[205][205];
    int solve(int l,int r){
      if(l>=r)return 0;
      if(dp[l][r]!=-1)return dp[l][r];
      int ans=INT_MAX;
      for(int k=l;k<=r;k++){
        int cost=k+max(solve(l,k-1),solve(k+1,r));
        ans=min(ans,cost);
      }
      return dp[l][r]=ans;
    }
    int getMoneyAmount(int n) {
        memset(dp,-1,sizeof dp);
        int value=solve(1,n);
        return value;
    }
};