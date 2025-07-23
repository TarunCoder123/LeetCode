class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos,neg;
        int n=nums.size();
        for(auto it:nums){
            if(it>=0)pos.push_back(it);
            else neg.push_back(it);
        }
        int i=0;
        for(int j=0;j<n;j+=2){
            nums[j]=pos[i];
            nums[j+1]=neg[i];
            i++;
        }
        return nums;
        
    }
};