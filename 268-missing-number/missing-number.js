/**
 * @param {number[]} nums
 * @return {number}
 */
var missingNumber = function(nums) {
    var ans=0;
    for(let i=0;i<nums.length;i++){
        ans=ans^nums[i];
    }
    for(let i=0;i<=nums.length;i++){
        ans=ans^i;
    }
    return ans;
};