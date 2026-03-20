class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
              vector<vector<int>> adj(numCourses);
	   vector<int> indegree(numCourses,0);
	   for(auto it:prerequisites){
	     adj[it[1]].push_back(it[0]);
		 indegree[it[0]]++;
	   }

       queue<int> q;
	   for(int i=0;i<numCourses;i++){
            if(indegree[i]==0)q.push(i);
	   }
       int count=0;
	   while(!q.empty()){
          auto it=q.front();
		  q.pop();
		  count++;

		  for(auto node:adj[it]){
		    indegree[node]--;
			if(indegree[node]==0)q.push(node);
		   }
		}

		return count==numCourses; 
    }
};