class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> v(n,0);
        int pindex=0, nindex=1;
        for(int i : nums){
            if(i<0){
                v[nindex]=i;
                nindex+=2;
            }else{
                v[pindex]=i;
                pindex+=2;
            }
        }
        return v;
    }
};