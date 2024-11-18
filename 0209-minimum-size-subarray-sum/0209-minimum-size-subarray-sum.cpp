class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
       int n=nums.size();
       int maxi=n+1;
       int sum=0;
       int j=0;
       int i=0;
       for(i=0;i<n;i++){
        sum+=nums[i];
        while(sum>=target and j<=i){
            maxi=min(maxi,i-j+1);
            sum-=nums[j];
            j++;
        }
       }
    return maxi==n+1?0:maxi; 
    }
};