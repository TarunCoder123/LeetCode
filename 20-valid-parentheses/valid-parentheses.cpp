class Solution {
public:
bool isValid(string s) {
  int len=s.length();
  stack<char> st;
  for(int i=0;i<len;i++){
    if(s[i]=='{' || s[i]=='(' || s[i]=='['){
       st.push(s[i]);
	 }else{
        if(st.size()>0 && ((st.top()=='[' && s[i]==']') || (st.top()=='{' && s[i]=='}') || (st.top()=='(' && s[i]==')'))){
		 st.pop();
		 }else{
		  st.push(s[i]);
		 }
	 }
  }

  return st.size()>0 ? false: true;

}
};