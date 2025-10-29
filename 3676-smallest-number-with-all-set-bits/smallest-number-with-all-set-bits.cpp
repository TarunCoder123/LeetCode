class Solution {
public:
    int smallestNumber(int n) {
      int count=1;
      int val=(1<<count)-1;
      while(val<n){
        count++;
        val=(1<<count)-1;
      }
      return val;  
    }
};