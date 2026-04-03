class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
       vector<array<int,3>> intervals;
       for(int i=0;i<profit.size();i++)intervals.push_back({endTime[i],startTime[i],profit[i]});
       sort(intervals.begin(),intervals.end());
       int m=intervals.size();
       vector<int> dp(m+1,0);
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