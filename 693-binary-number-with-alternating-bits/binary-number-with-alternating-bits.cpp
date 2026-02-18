class Solution {
public:
    bool hasAlternatingBits(int n) {
       int value=-1;
       while(n>0){
        //    cout<<n<<" n "<<endl;
           int rem=n%2;
        //    cout<<rem<<" rem "<<value<<" value "<<endl;
           if(value==-1){
            value=rem;
           }else if(value==rem){
            return false;
           }else{
           value=rem;
           }
           n/=2;
       }
       return true;
    }
};