class Solution {
public:
    int longestSubarray(vector<int>& nums) {
    int ans=0,curr=0,maxValue=0;
      for(auto it:nums){
        if(it>maxValue){
           maxValue=it;
           ans=curr=0;
        }
        
         if(it==maxValue){
            curr++;
        }else{
            curr=0;
        }

        ans=max(ans,curr);
      }  
      return ans;
    }
};