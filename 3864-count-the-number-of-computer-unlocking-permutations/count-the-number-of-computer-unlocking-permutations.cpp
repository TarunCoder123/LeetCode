class Solution {
public:
    static const int MOD = 1e9+7;
    // vector<int> pref
    int countPermutations(vector<int>& complexity) {
        int n=complexity.size();
        int val=complexity[0];
        sort(complexity.begin(),complexity.end());
        if(complexity[0]==complexity[1] || complexity[0]!=val){
            return 0;
        }
        long long ans=1;
        for(int i=2;i<n;i++)ans=(ans*i)%MOD;
        return (int)ans;
    }
};