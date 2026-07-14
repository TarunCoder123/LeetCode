class Solution {
public:
    int f(int i,int s,vector<int> &nums,vector<vector<int>> &dp){
        if(i==-1){
            if(s==0)return 1;
            return 0;
        }
        if(dp[i][s]!=-1)return dp[i][s];
        int not_take=f(i-1,s,nums,dp);
        int take=0;
        if(s>=nums[i]){
            take=f(i-1,s-nums[i],nums,dp);
        }
        return dp[i][s]=take+not_take;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
    int n=nums.size();
    int sum=0;
    for(auto it:nums)sum+=it;
    int s=(sum-target);
    if(s<0)return 0;
    if(s%2==1)return 0;
    s/=2;
    vector<vector<int>> dp(n+1,vector<int>(s+1,-1));
    return f(n-1,s,nums,dp);  
    }
};