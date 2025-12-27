class Solution {
public:
    int dp[24][24][4];
    int solve(int start,int end,int state,vector<int> &nums){
        if(start>end)return 0;
        if(dp[start][end][state]!=-1)return dp[start][end][state];
        int ans=-1e9;
        int ans1=1e9;
        if(state==1){
            ans=max(ans,nums[start]+solve(start+1,end,2,nums));
            ans=max(ans,nums[end]+solve(start,end-1,2,nums));
        }else{
            ans1=min(ans1,-1*nums[start]+solve(start+1,end,1,nums));
            ans1=min(ans1,-1*nums[end]+solve(start,end-1,1,nums));   
        }
        cout<<ans<<" ans "<<ans1<<" ans1 "<<start<<" start "<<end<<" end ";
        cout<<endl;
        return dp[start][end][state]=(state==2?ans1:ans);         
        // return ans;
    }
    bool predictTheWinner(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
       int n=nums.size();
       int value=solve(0,n-1,1,nums);
       return value>=0; 
    }
};