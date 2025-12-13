class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        int i=0,j=0;
        int ans=0;
        map<char,int> m;
        while(j<n){
            m[s[j]]++;
            int windowSize=j-i+1;
            if(m.size()==windowSize){
                ans=max(ans,windowSize);
                j++;
            }else{
                while(m.size()<(j-i+1)){
                cout<<(j-i+1)<<" (j-i+1) "<<m.size()<<" m.size() "<<endl;
                    m[s[i]]--;
                    if(m[s[i]]==0){
                        m.erase(s[i]);
                    }
                    i++;
                }
                int windowSize=j-i+1;
                if(m.size()==windowSize){
                    cout<<i<<" i "<<j<<" j "<<windowSize<<" windowSize"<<endl;
                   ans=max(ans,windowSize); 
                }
                j++;
            }
        }
        return ans;
    }
};