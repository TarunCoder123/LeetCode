class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
       int n=matrix.size();
       vector<vector<int>> v(n);
       for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(matrix[i][j]==1){
                v[i].push_back(j);
                v[j].push_back(i);
            }
        }
       }

       vector<int> ans;
       for(auto it:v){
        ans.push_back(it.size()/2);
       } 

       return ans;
    }
};