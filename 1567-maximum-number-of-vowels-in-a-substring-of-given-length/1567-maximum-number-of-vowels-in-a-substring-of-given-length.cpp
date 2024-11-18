class Solution {
public:
    int maxVowels(string s, int k) {
    int start=0,end=0;
    int count=0,maxi=0;
    while(end<s.length()){
        if(end-start+1<k){
            if(s[end]=='a'||s[end]=='e'||s[end]=='i'||s[end]=='o'||s[end]=='u'){
                count++;
            }
            end++;
        }else{
            if(s[end]=='a'||s[end]=='e'||s[end]=='i'||s[end]=='o'||s[end]=='u'){
                count++;
            }
            end++;
            maxi=max(maxi,count);
            if(s[start]=='a'||s[start]=='e'||s[start]=='i'||s[start]=='o'||s[start]=='u'){
                count--;
            }
            start++;
        }
    }
    return maxi; 
    }
};