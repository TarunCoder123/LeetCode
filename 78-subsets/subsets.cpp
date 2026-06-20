class Solution {
public:
void solving(int i,int n,vector<int> &nums,vector<int> &sub,vector<vector<int>> &answer){
// Base case
if(i==n){
   answer.push_back(sub);
   return;
}

sub.push_back(nums[i]);
solving(i+1,n,nums,sub,answer);
sub.pop_back();
solving(i+1,n,nums,sub,answer);
}

vector<vector<int>> subsets(vector<int>& nums) {
  vector<int> sub;
  int n=nums.size();
  vector<vector<int>> answer;
  solving(0,n,nums,sub,answer);
  return answer;
}

};