class Solution {
public:
bool checkStrings(string s1, string s2) {
   unordered_map<char,int> even,odd;
   int n=s1.length();
   for(int i=0;i<n;i+=2){
        even[s1[i]]++;
   }
   for(int i=1;i<n;i+=2){
        odd[s1[i]]++;
   }
   for(int i=0;i<n;i+=2){
       if(even.find(s2[i])==even.end()){
           return false;
	   }
	   even[s2[i]]--;
	   if(even[s2[i]]==0)even.erase(s2[i]);
   }
   for(int i=1;i<n;i+=2){
       if(odd.find(s2[i])==odd.end()){
           return false;
	   }
	   odd[s2[i]]--;
	   if(odd[s2[i]]==0)odd.erase(s2[i]);
   }

   if(odd.size()==0 && even.size()==0)return true;
   return false;
}
};