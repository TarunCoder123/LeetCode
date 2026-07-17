class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int mx=-1;
        vector<int> ans;
        for(auto it:nums){
            mx=max(mx,it);
            ans.push_back(__gcd(mx,it));
        }
        // for(auto it:ans)cout<<it<<" ";
        sort(ans.begin(),ans.end());
        long long val=0;
        int left=0;
        int right=ans.size()-1;
        while(left!=right && left<right ){
            val+=__gcd(ans[left],ans[right]);
            left++;
            right--;
        }
        return val;
    }
};