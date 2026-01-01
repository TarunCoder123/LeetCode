class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        vector<int> ans;
        int j=n-1;
        int carry=1;
        while(j>=0 && carry==1){
            int value=digits[j]+1;
            ans.push_back(value%10);
            carry=value/10;
            j--;
        }
        while(j>=0){
            ans.push_back(digits[j]);
            j--;
        }
        if(carry){
            ans.push_back(1);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};