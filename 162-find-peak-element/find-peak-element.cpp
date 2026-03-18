class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        int ans=right;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(mid+1<nums.size() && (nums[mid]>nums[mid+1])){
                ans=mid;
                right=mid-1;
            }else{
                left=mid+1;
            }
        }

        return ans;

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[mid + 1]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;        
    }
};