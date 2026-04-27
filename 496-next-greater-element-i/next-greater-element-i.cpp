class Solution {
public:
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
  int n=nums2.size();
  vector<int> ans(n,-1);
  map<int,int> m;
  for(int i=0;i<n;i++){
    m[nums2[i]]=i;
  }
  stack<int> st;
  ans[n-1]=-1;
  st.push(nums2[n-1]);
  for(int i=n-2;i>=0;i--){
   int value=nums2[i];
   while(st.size()>0 && st.top()<=value){
    st.pop();
   }
   if(st.size()==0)ans[i]=-1;
   else ans[i]=st.top();
   st.push(nums2[i]);
  }
  vector<int> real_ans(nums1.size(),0);
  for(int i=0;i<nums1.size();i++){
   real_ans[i]=ans[m[nums1[i]]];
  }
  return real_ans;
}
};