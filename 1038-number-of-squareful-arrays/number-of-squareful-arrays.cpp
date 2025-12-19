class Solution {
private:
    int n, res = 0;
    inline bool perfect(int num){
        int root = sqrt(num);
        return root * root == num;
    }
    void dfs(vector<int> nums , int idx){
        if(idx == n){
            ++res;
            return;
        }
        for(int i = idx; i < n; ++i){
            if(i == idx || nums[idx] != nums[i]){
                swap(nums[idx] , nums[i]);
                if(idx == 0 || perfect(nums[idx] + nums[idx - 1])) dfs(nums , idx + 1);
            }
        }
    }
public:
    int numSquarefulPerms(vector<int>& nums) {
        n = nums.size();
        sort(nums.begin() , nums.end());
        dfs(nums , 0);
        return res;
    }
};