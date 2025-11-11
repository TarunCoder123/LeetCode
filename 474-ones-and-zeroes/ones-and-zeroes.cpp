class Solution {
public:
    vector<vector<vector<int>>> dp;
    int value(int index,vector<pair<int,int>> &v,int m,int n){
        if(m<0 || n<0)return -1e8;
        if(index==0){
            if(v[index].first>m || v[index].second>n){
                return 0;
            }else{
                return 1;
            }
        }
        if(dp[index][m][n]!=-1)return dp[index][m][n];
        int len1=1+value(index-1,v,m-v[index].first,n-v[index].second);
        int len2=value(index-1,v,m,n);
        return dp[index][m][n]=max(len1,len2);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
       int len=strs.size();
       dp.resize(strs.size()+2, vector<vector<int>>(m+2, vector<int>(n+2, -1)));
       vector<pair<int,int>> v;
       for(auto it:strs){
        int ones=0,zeros=0;
        for(int i=0;i<it.length();i++){
            if(it[i]=='0')zeros++;
            else ones++;
        }
        v.push_back({zeros,ones});
       }
       return value(len-1,v,m,n); 
    }
};