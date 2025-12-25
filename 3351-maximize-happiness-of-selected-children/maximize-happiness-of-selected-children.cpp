class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
       long long sum=0;
       sort(happiness.begin(),happiness.end());
       reverse(happiness.begin(),happiness.end());
       int value=0;
       while(k>0 && value<happiness.size()){
        if(happiness[value]-value>0){
        sum+=(happiness[value]-value);
        }
        value++;
        k--;
       }   
       return sum;
    }
};