class Solution {
public:
int f(int i,int j,int k ,vector<vector<int>> &coins,vector<vector<vector<int>>> &dp){
  if(i<0 || j<0)return -1e9;
  if(i==0 && j==0){
     if(k>0 && coins[i][j]<0)return 0;
	 return coins[i][j];
   }
   if(dp[i][j][k]!=INT_MIN)return dp[i][j][k];
   int up=f(i-1,j,k,coins,dp);
   int left=f(i,j-1,k,coins,dp);

   int ans=coins[i][j]+max(up,left);

   if(coins[i][j]<0 && k>0){
     int up1=f(i-1,j,k-1,coins,dp);
	 int left1=f(i,j-1,k-1,coins,dp);

	 int ans2=0+max(up1,left1);

	 ans=max(ans,ans2);
   }

   return dp[i][j][k]=ans;
}

int maximumAmount(vector<vector<int>>& coins) {
    int n=coins.size();
	int m=coins[0].size();
    int k=2;
	vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(k+1,INT_MIN)));
	return f(n-1,m-1,k,coins,dp);
}
};