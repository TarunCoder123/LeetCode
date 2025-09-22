class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
       map<int,int> m;
       for(auto it:nums){
        m[it]++;
       }
       int maxi=0;
       int count=0;
       for(auto it:m){
          if(maxi<it.second){
            maxi=it.second;
            count=1;
          }else if(maxi==it.second){
            count++;
          }
       }
       return count*maxi;
    }
};