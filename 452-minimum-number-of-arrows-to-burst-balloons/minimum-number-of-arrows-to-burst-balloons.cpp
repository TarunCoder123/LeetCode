class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& interval) {
        vector<array<int,3>> intervals;
       for(int i=0;i<interval.size();i++)intervals.push_back({interval[i][1],interval[i][0],1});
       sort(intervals.begin(),intervals.end());
       int m=intervals.size();
       vector<int> dp(m+1,0);
       vector<int> ends;
       for(auto it:intervals)ends.push_back(it[0]);
       for(int i=1;i<=m;i++){
         int startTime=intervals[i-1][1];
         int profit=intervals[i-1][2];
         int start=startTime<=INT_MIN ? INT_MIN : startTime-1; 

         int j=upper_bound(ends.begin(),ends.end(),start)-ends.begin();
         dp[i]=max(dp[i-1],dp[j]+profit);
       }      
       return dp[m]; 
    }
};