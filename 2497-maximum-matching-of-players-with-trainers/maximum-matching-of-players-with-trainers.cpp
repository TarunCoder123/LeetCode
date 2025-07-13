class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        vector<pair<int,int>> v;
        int n=players.size();
        int rem_player=0;
        int ans=0;
        for(int i=0;i<n;i++){
            v.push_back({players[i],0});
        }
        for(int j=0;j<trainers.size();j++){
            v.push_back({trainers[j],1});
        }
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++){
            if(v[i].second==0){
               rem_player++;
            }else{
                if(rem_player>0){
                   ans++;
                   rem_player--;
                }
            }
        }
        return ans;
    }
};