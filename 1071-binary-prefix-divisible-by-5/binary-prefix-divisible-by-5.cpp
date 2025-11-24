class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
       int n=nums.size();
       vector<bool> answer(n,false);
       long long number=0;
       for(int i=0;i<n;i++){
          number=((number<<1)+nums[i])%5;
          answer[i]= (number==0)?true:false;
       }
       return answer;  
    }
};