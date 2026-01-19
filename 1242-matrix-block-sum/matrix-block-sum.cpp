class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
    int m=mat.size();
    int n=mat[0].size();
   vector<vector<int>> pref(m+1,vector<int>(n+1,0));

  for(int i=1;i<=m;i++){
    for(int j=1;j<=n;j++){
        pref[i][j]=mat[i-1][j-1]+pref[i][j-1]+pref[i-1][j]-pref[i-1][j-1];
    }
  } 

  vector<vector<int>> ans(m,vector<int>(n,0));

  for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
        int start_i=max(i-k,0);
        int start_j=max(j-k,0);
        int end_i=min(i+k,m-1);
        int end_j=min(j+k,n-1);

        ans[i][j]=pref[end_i+1][end_j+1]-pref[end_i+1][start_j]-pref[start_i][end_j+1]+pref[start_i][start_j];
    }
  }
   return ans;
    }
};