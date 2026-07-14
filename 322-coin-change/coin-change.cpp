class Solution {
public:
    int solve(int ind,int amount,vector<int> &coins,vector<vector<int>> &dp){
        // base case
        // cout<<ind<<" ind "<<amount<<" amount "<<endl;
        if(amount==0)return 0;
        if(amount<0)return 1e7;
        if(ind==0){
          if((amount%coins[0])==0)return amount/coins[0];
          return 1e7;
        }
        if(dp[ind][amount]!=-1)return dp[ind][amount];
        int not_take=solve(ind-1,amount,coins,dp);
        int take=1e7;
        if(coins[ind]<=amount){
            take=1+solve(ind,amount-coins[ind],coins,dp);
        }
        return dp[ind][amount]=min(not_take,take);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1,-1));
        int ans = solve(n-1,amount,coins,dp);
        return ans >= 1e7 ? -1:ans;
    }
};