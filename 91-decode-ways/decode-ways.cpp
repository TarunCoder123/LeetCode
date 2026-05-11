class Solution {
public:
int solve(int i,string s,vector<int> &dp){
  if(i>s.length())return 0;
  if(i==s.length())return 1;
  if(dp[i]!=-1)return dp[i];
  int cost1=0;
  if(s[i]!='0')cost1=solve(i+1,s,dp);
  if((s[i]=='1') || ((s[i]=='2') && (i+1<s.length()) &&  (s[i+1]<='6'))){
    cost1+=solve(i+2,s,dp);
  }
  return dp[i]=cost1;
}

int numDecodings(string s) {
   int n=s.length();
   vector<int> dp(n+3,-1);
   return solve(0,s,dp);
}
};