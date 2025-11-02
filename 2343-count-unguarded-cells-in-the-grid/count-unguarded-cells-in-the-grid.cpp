class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m,vector<int>(n,0));
        for(auto it:guards){
            grid[it[0]][it[1]]=2;
        }
        for(auto it:walls){
            grid[it[0]][it[1]]=2;
        }
        int dirs[5]={-1,0,1,0,-1};
        for(auto &e:guards){
            for(int k=0;k<4;k++){
               int x=e[0],y=e[1];
               int dx=dirs[k],dy=dirs[k+1];

               //check cells in current direction until hitting boundary
               while(x+dx>=0 and x+dx<m and y+dy>=0 and y+dy<n and grid[x+dx][y+dy]<2){
                x+=dx;
                y+=dy;
                grid[x][y]=1;
               }
            }
        }
        int unguardedCount=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0)unguardedCount++;
            }
        }
        return unguardedCount;
    }
};