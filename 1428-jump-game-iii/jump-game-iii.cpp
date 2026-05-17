class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
    int n=arr.size();
    vector<bool> vis(n,false);
    vis[start]=true;
    queue<int> q;
    q.push(start);
    while(!q.empty()){
      int ind=q.front();
      q.pop();

      if(arr[ind]==0){
        return true;
      }

      if(ind+arr[ind]<n and vis[ind+arr[ind]]==false){
        q.push(ind+arr[ind]);
        vis[ind+arr[ind]]=true;
      }

      if(ind-arr[ind]>=0 and vis[ind-arr[ind]]==false){
        q.push(ind-arr[ind]);
        vis[ind-arr[ind]]=true;
      }
    }
    return false;    
    }
};