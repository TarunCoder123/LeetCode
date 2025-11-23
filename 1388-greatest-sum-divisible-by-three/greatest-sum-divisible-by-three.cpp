class Solution {
public:
    int solve(int index,int sum,vector<int> &nums,vector<vector<int>> &v){
        if(index==0){
            // pick
            int rem=nums[index]%3;
            if((sum+rem)%3==0)return nums[index];
            if(sum==0)return 0;
            return -1e8;
        }
        if(v[index][sum]!=-1)return v[index][sum];
        int val=solve(index-1,sum,nums,v);
        int val2=nums[index]+solve(index-1,(sum+nums[index]%3)%3,nums,v);
        return v[index][sum]=max(val,val2);
    }
    int maxSumDivThree(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> v(n,vector<int>(3,-1));
        int ans=solve(n-1,0,nums,v);
        return ans;
    }
};