class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        if(n<=2)return n;
        int value=1;
        while(value<=n){
            value*=2;
        }
        return value;
    }
};