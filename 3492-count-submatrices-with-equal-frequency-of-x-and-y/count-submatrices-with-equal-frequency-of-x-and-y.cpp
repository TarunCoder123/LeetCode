class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
      int n=grid.size();
      int m=grid[0].size();
      vector<vector<int>> xgrid(n,vector<int>(m,0));
      vector<vector<int>> ygrid(n,vector<int>(m,0));  
      int count=0;
      for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='X')xgrid[i][j]=1;
            if(grid[i][j]=='Y')ygrid[i][j]=1;
            if(i>0){
                xgrid[i][j]+=xgrid[i-1][j];
                ygrid[i][j]+=ygrid[i-1][j];
            }
            if(j>0){
                xgrid[i][j]+=xgrid[i][j-1];
                ygrid[i][j]+=ygrid[i][j-1];
            }
            if(i>0 && j>0){
                xgrid[i][j]-=xgrid[i-1][j-1];
                ygrid[i][j]-=ygrid[i-1][j-1];                
            }

           if(xgrid[i][j]>0 && xgrid[i][j]==ygrid[i][j])count++;

        }
      }

      return count;

    }
};