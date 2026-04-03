class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& interval) {
        vector<array<long long,3>> intervals;
       for(int i=0;i<interval.size();i++)intervals.push_back({interval[i][1],interval[i][0],(interval[i][2]+(interval[i][1]-interval[i][0]))});
       sort(intervals.begin(),intervals.end());
       for(auto it:intervals)cout<<it[2]<<" "<<endl;
       int m=intervals.size();
       vector<long long> dp(m+1,0);
       vector<int> ends;
       for(auto it:intervals)ends.push_back(it[0]);
       for(int i=1;i<=m;i++){
         int startTime=intervals[i-1][1];
         int profit=intervals[i-1][2];

         int j=upper_bound(ends.begin(),ends.end(),startTime)-ends.begin();
         dp[i]=max(dp[i-1],dp[j]+profit);
       }      
       return dp[m];  
    }
};