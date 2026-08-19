class Solution {
public:
    int Target;
    const int INF=1e9;
    int dp[103][22][104];
    int solve(int index,int prev_color,int neighbour,vector<int>& houses, vector<vector<int>>& cost){
        // base case
        if (neighbour > Target)return INF;
        if(index < 0)return (neighbour == Target) ? 0 : INF;
        if (dp[index][prev_color][neighbour] != -1)return dp[index][prev_color][neighbour];
        int ans=INF;
        if(houses[index]!=0){
              int new_neighbour=(prev_color==(houses[index]))?neighbour:neighbour+1;
              return solve(index-1,houses[index],new_neighbour,houses,cost); 
            }
        for(int j=0;j<cost[index].size();j++){
              int new_neighbour=(prev_color==(j+1))?neighbour:neighbour+1;
              ans=min(ans,cost[index][j]+solve(index-1,j+1,new_neighbour,houses,cost)); 
        }
        return dp[index][prev_color][neighbour] = ans;
    }
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        Target=target;
        memset(dp, -1, sizeof(dp));
       int ans=solve(m-1,0,0,houses,cost); 
       return (ans>=INF)?-1:ans;
    }
};