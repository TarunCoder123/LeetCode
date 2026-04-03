class Solution {
public:
int dp[11][2][1<<10][2];

int solve(int pos,int tight,int mask,int leading_zero,string s){
    if(pos==s.size())return 1;
	if(dp[pos][tight][mask][leading_zero]!=-1)return dp[pos][tight][mask][leading_zero];
	int limit=tight ? (s[pos]-'0'):9;
	int ans=0;
	for(int d=0;d<=limit;d++){
	  int new_tight=tight && (d==limit);
    if(leading_zero && d==0){
      ans+=solve(pos+1,new_tight,mask,1,s);
	}else{
       if(mask & (1<<d))continue;
	   ans+=solve(pos+1,new_tight,mask|(1<<d),0,s);
	}
    }

	return dp[pos][tight][mask][leading_zero]=ans;
}


int countNumbersWithUniqueDigits(int n) {
   if(n==0)return 1;
   int maxNum=pow(10,n)-1;
   string s=to_string(maxNum);
   memset(dp,-1,sizeof(dp));
   return solve(0,1,0,1,s);
}
};