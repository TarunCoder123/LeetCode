class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
       vector<int> ans;
       int count=0;
       for(int i=0;i<bank.size();i++){
          int one_count=0;
          for(int j=0;j<bank[i].size();j++){
            if(bank[i][j]=='1'){
                one_count++;
            }
          }
           if(ans.size()>=1){
              if(one_count>0){count+=one_count*ans.back();}
           }
           if(one_count>0){
            ans.push_back(one_count);
           }
       }
       return count; 
    }
};