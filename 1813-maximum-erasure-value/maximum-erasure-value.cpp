class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int l=0,r=0;
        int n=nums.size();
        int ans=0;
        int sum=0;
        map<int,int> m;
        while(r<n){
            // add the value to the sum
            sum+=nums[r];
            m[nums[r]]++;
            if(m.size()==r-l+1){
                ans=max(ans,sum);
            }else{
                while(m.size()!=r-l+1){
                    sum-=nums[l];
                    if(m[nums[l]]==1){
                        m[nums[l]]--;
                        m.erase(nums[l]);
                    }else{
                        m[nums[l]]--;
                    }
                    l++;
                }
            }
            r++;
        }
       return ans;
    }
};