class Solution {
public:
    int minimumPushes(string word) {
        int ans=0;
        int total=0;
        int value=1;
        for(int i=0;i<word.length();i++){
            ans+=value;
            total+=1;
            if(total>=8){
                total=0;
                value++;
            }
        }
        return ans;
    }
};