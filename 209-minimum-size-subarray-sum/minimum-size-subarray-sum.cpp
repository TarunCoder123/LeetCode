class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int mini=1e9;
        int sum=0;
        int left=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
            while(left<=i and target<=sum){
                mini=min(mini,(i-left+1));
                sum-=nums[left++];
            }
        }
        return mini==1e9?0:mini;
    }
};