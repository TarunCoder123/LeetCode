class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        int count=0;
        int prev=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(prev==INT_MIN){
                prev=nums[i];
                count=1;
            }else if(prev<nums[i]){
                prev=nums[i];
                count++;
            }else{
                ans.push_back(count);
                prev=nums[i];
                count=1;
            }
        }
        ans.push_back(count);
        cout<<ans.size()<<endl;
        int maxi=(ans[0]/2);
        for(int i=1;i<ans.size();i++){
            maxi=max(maxi,min(ans[i-1],ans[i]));
            maxi=max(maxi,(ans[i]/2));
        }
        return maxi;
    }
};