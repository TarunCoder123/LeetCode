class Solution {
public:
    using ll=long long;
    vector<pair<int,int>> p;
    int n;
    ll dp[1005][1005];
    ll f(int i,int prev){
        if(i>=n)return 0;
        if(dp[i][prev]!=-1)return dp[i][prev];
        ll not_take=f(i+1,prev);
        ll take=-1e14;
        if(p[i].second>=prev){
        take=p[i].first+f(i+1,p[i].second);
        }
        return dp[i][prev]=max(take,not_take);
    }
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
    n=ages.size();
    for(int i=0;i<n;i++){
        p.push_back({scores[i],ages[i]});
    } 
    sort(p.begin(),p.end());
    memset(dp,-1,sizeof(dp));
    return f(0,0);
    }
};