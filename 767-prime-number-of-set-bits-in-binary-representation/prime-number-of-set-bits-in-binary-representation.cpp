class Solution {
public:
    void findPrime(map<int,int>&m){
        int count=0;
        for(int i=2;i<=50;i++){
            count=0;
            for(int j=2;j<=i;j++){
               if(i%j==0)count++;
            }
            if(count==1)m[i]++;
        }
    }
    int countPrimeSetBits(int left, int right) {
        map<int,int> m;
        findPrime(m);
        int count=0;
        for(int i=left;i<=right;i++){
            int value=i;
            int set_bit_count=0;
            while(value>0){
                int bit=value&1;
                if(bit==1){
                    set_bit_count++;
                }
                value=value>>1;
                // cout<<value<<"value "<<bit<<"bit ";
            }
            cout<<set_bit_count<<" set_bit_count "<<endl;
            if(m[set_bit_count]>0)count++;
        }
        return count;
    }
};