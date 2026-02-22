class Solution {
public:
    int binaryGap(int n) {
        string s="";
        while(n>0){
            int dig=n&1;
            s+=dig+'0';
            n>>=1;
        }
        reverse(s.begin(),s.end());
        int start=-1;
        int ans=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='1'){
                if(start==-1){
                    start=i;
                }else{
                    ans=max(i-start,ans);
                    start=i;
                }
            }
        }
        return ans;
    }
};