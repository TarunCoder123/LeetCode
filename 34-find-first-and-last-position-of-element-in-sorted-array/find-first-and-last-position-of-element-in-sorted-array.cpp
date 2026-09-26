class Solution {
public:
    int flooring(vector<int> &nums,int x){
       int n=nums.size();
       int low=0,high=n-1;
       int ans=-1;
       while(low<=high){
        int mid=(low+high)/2;
        if(nums[mid]==x){
            ans=mid;
            high=mid-1;
        }else if(nums[mid]>=x){
            high=mid-1;
        }else{
            low=mid+1;
        }
       }
       return ans;
    }
    int ceiling(vector<int> &nums,int x){
       int n=nums.size();
       int low=0,high=n-1;
       int ans=-1;
       while(low<=high){
        int mid=(low+high)/2;
        if(nums[mid]==x){
            ans=mid;
            low=mid+1;
        }else if(nums[mid]<x){
            low=mid+1;
        }else{
            high=mid-1;
        }
       }
       return ans;
    }
    vector<int> searchRange(vector<int>& nums, int x) {
       int value1=flooring(nums,x);
      int value2=ceiling(nums,x);
      return {value1,value2}; 
    }
};