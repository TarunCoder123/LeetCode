class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i=0;
        for(int j=1;j<n;j++){
            if(nums[i]!=nums[j]){
//i++before so we can place the new unique number at the next available position 
                i++;
                nums[i] = nums[j];
            }
        }
    return i+1;//new length
    }
};