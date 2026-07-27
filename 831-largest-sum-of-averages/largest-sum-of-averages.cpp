class Solution {
public:
    vector<vector<double>> dp;
    int n;
    double f(int idx,vector<int> &nums,int k){
        if(idx>=n)return 0;
        if(!k)return INT_MIN;
        if(dp[idx][k]!=-1)return dp[idx][k];
        double ans=INT_MIN;
        double sum=0;
        for(int i=idx;i<n;i++){
           sum+=nums[i];
           ans=max(ans,sum/(i-idx+1)+f(i+1,nums,k-1));
        }
        return dp[idx][k]=ans;
    }
    double largestSumOfAverages(vector<int>& nums, int k) {
    n=nums.size();
    dp=vector<vector<double>> (n+1,vector<double>(k+1,-1));
    return f(0,nums,k);    
    }
};