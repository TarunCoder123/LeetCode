class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int> ans;
        int value=nums[0];
        int i=0;
        while(i<n){
            if(value!=nums[i]){
                ans.push_back(value);
                value++;
            }else{
                value++;
                i++;
            }
        }
        return ans;
    }
};