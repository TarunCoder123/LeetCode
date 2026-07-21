class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int originalOnes=0;
        for(auto it:s){
            if(it=='1')originalOnes++;
        }
        string t='1'+s+'1';

        vector<pair<char,int>> vs;

        for(int i=0;i<t.length();i++){
            if(vs.empty() || vs.back().first!=t[i]){
                vs.push_back({t[i],1});
            }else{
                vs.back().second++;
            }
        }

                int bestGain = 0;

        for (int i = 1; i + 1 < vs.size(); i++) {
            if (vs[i].first == '1' &&
                vs[i-1].first == '0' &&
                vs[i+1].first == '0') {
                   bestGain = max(bestGain,vs[i-1].second + vs[i+1].second);
            }
        }

        return originalOnes + bestGain;

    }
};