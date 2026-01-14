class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
       vector<pair<int,int>> events;
       for(int i=0;i<bookings.size();i++){
        events.push_back({bookings[i][0],bookings[i][2]});
        events.push_back({bookings[i][1]+1,-1*bookings[i][2]});
       } 
       sort(events.begin(),events.end());
       vector<int> ans(n+2,0);
       for(auto it:events){
         ans[it.first]+=it.second;
       }
       for(int i=1;i<=n;i++){
        ans[i]+=ans[i-1];
       }
       ans.pop_back();
       reverse(ans.begin(),ans.end());
       ans.pop_back();
       reverse(ans.begin(),ans.end());
       return ans;
    }
};