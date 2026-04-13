class Solution {
public:
int getMinDistance(vector<int>& nums, int target, int start) {
    int n=nums.size();
	int mini=n;
	for(int i=0;i<=start && i<n;i++){
      if(nums[i]==target)mini=min(mini,start-i);
	}
	for(int i=start+1;i<n;i++){
      if(nums[i]==target)mini=min(mini,i-start);
	}
    cout<<mini<<" mini "<<endl;
	return mini;
}
};