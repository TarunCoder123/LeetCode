class Solution {
public:
bool solve(int value,vector<vector<int>> &tasks,int n){
  for(int i=0;i<n;i++){
    if(value<tasks[i][1]){
       return false;
    }
	value-=tasks[i][0];
  }
  if(value<0)return false;
  return true;
}

int minimumEffort(vector<vector<int>>& tasks) {
  int n=tasks.size();
  int maxi=-1;
  int sum=0;
  for(auto it:tasks){
    maxi=max(maxi,it[1]);
	sum+=it[1];
   }
sort(tasks.begin(), tasks.end(), [](vector<int>& a, vector<int>& b) {
    return (a[1] - a[0]) > (b[1] - b[0]);
});

   int low=maxi;
   int high=sum;
   int ans=-1;
   while(low<=high){
    int mid=low+(high-low)/2;
	if(solve(mid,tasks,n)){
       ans=mid;
	   high=mid-1;
	}else{
       low=mid+1;
	}
   }
   return ans;
}
};