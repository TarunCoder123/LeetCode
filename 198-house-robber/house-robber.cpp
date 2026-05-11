class Solution {
public:
int solve(int ind,vector<int> nums,vector<int> &dp,int n){
  if(ind>=n)return 0;
  if(dp[ind]!=-1)return dp[ind];
  int cost1=solve(ind+1,nums,dp,n);
  int cost2=solve(ind+2,nums,dp,n)+nums[ind];
  return dp[ind]=max(cost1,cost2);
}

int rob(vector<int>& nums) {
  int n=nums.size();
  vector<int> dp(n+2,-1);
  return solve(0,nums,dp,n);
}
};