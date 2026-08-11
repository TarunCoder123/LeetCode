class Solution {
public:
    int n;
    int dp[24][10100];
    int solve(int i,vector<int> &rods,int sum){
        if(i==n){
            return sum==0?0:-1e6;
        }
        if(dp[i][sum+5050]!=-1)return dp[i][sum+5050];
        int pick1=rods[i]+solve(i+1,rods,sum+rods[i]);
        int pick2=solve(i+1,rods,sum-rods[i]);
        int pick3=solve(i+1,rods,sum);
        return dp[i][sum+5050]=max(pick1,max(pick2,pick3));
    }
    int tallestBillboard(vector<int>& rods) {
        n=rods.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,rods,0);
    }
};