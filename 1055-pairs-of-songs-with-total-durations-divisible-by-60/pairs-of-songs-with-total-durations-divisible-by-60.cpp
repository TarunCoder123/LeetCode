class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> v(60,0);
        for(int i=0;i<time.size();i++){
            v[time[i]%60]++;
        }
        long long ans=0;
        for(int i=1;i<30;i++){
            ans+=(v[i]*v[60-i]);
        }
        ans+=(1ll*(v[0])*(v[0]-1))/2;
        ans+=(1ll*(v[30])*(v[30]-1))/2;
        return ans;
    }
};