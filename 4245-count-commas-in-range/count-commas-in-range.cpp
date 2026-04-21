class Solution {
public:
    int countCommas(int n) {
       if(n<=999)return 0;
       int count=n-1000;
       return count+1; 
    }
};