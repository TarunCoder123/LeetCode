class Solution {
public:
    int m,n;
    int arr[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
    void dfs(int row,int col,vector<vector<int>> &image,int color,int ori){
        image[row][col]=color;
        for(int i=0;i<4;i++){
            int newx=row+arr[i][0];
            int newy=col+arr[i][1];
            if(newx>=0 and newx<n and newy>=0 and newy<m and image[newx][newy]==ori){
                dfs(newx,newy,image,color,ori);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        n=image.size();
        m=image[0].size();
        if(image[sr][sc]==color)return image;
        dfs(sr,sc,image,color,image[sr][sc]);
        return image;
    }
};