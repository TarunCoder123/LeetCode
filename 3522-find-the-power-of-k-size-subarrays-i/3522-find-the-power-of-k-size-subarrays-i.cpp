class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
    int n=nums.size();
    vector<int> ans1;
    for(int i=0;i<=(n-k);i++){
        bool ans=true;
        for(int j=i;j<i+k;j++){
            if(j!=i){
                if(nums[j]!=nums[j-1]+1){
                    ans=false;
                }
            }
        }
        if(ans)ans1.push_back(nums[i+k-1]);
        else ans1.push_back(-1);
    }
    return ans1;
    }
};