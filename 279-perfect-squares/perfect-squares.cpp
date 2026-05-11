class Solution {
public:
int numSquares(int n) {
  vector<int> dp(n+1,0);
  for(int i=1;i<=n;i++){
    int res=1e4;
	for(int j=1;j*j<=i;j++){
        res=min(res,1+dp[i-j*j]);
      }
	  dp[i]=res;
   }
   return dp[n];
}
};