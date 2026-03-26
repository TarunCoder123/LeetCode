class Solution {
public:

bool bfsColor(int node,int colorValue,vector<vector<int>> &graph,vector<int> &color){
  queue<int> q;
  q.push(node);
  color[node]=colorValue;
  while(!q.empty()){
	  int node=q.front();
	  q.pop();
	  for(auto neigh:graph[node]){
        if(color[neigh]==-1){
           q.push(neigh);
           color[neigh]=!color[node];
		}else if(color[neigh]==color[node])return false;
	  }
  }
  return true;
}

bool isBipartite(vector<vector<int>>& graph) {
     int n=graph.size();
	 vector<int> color(n,-1);
	 for(int i=0;i<n;i++){
      if(color[i]==-1){
          if(!bfsColor(i,0,graph,color))return false;
	    }
	 }

	 return true;
}

};