class Solution {
public:
    int dirx[8]={-1,0,1,-1,1,-1,0,1};
    int diry[8]={1,1,1,0,0,-1,-1,-1};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int n=grid.size();
    vector<vector<bool>> vis(n,vector<bool>(n,false));
    if(grid[0][0]==1 or grid[n-1][n-1]==1)return -1;  
    if(n==1 and grid[0][0]==0)return 1;
    vis[0][0]=true;
    queue<pair<int,int>> q;
    q.push({0,0}); 
    int count=0;
    while(!q.empty()){
    int size=q.size();
    count++;
    for(int i=0;i<size;i++){
    int prevx=q.front().first;
    int prevy=q.front().second;
    q.pop();

    if(prevx==n-1 and prevy==n-1){
        return count;
    }

    for(int k=0;k<8;k++){
        int newx=prevx+dirx[k];
        int newy=prevy+diry[k];

        if(newx<0 || newx>=n || newy<0 || newy>=n)continue;
        if(grid[newx][newy]==1 or vis[newx][newy]==1)continue;
        q.push({newx,newy});
        vis[newx][newy]=1;
    }
    }
    }
    return -1; 
    }
};