class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n=colors.size();
        int maxi=-1;
        for(int i=0;i<n;i++){
            int c1=colors[i];
            for(int j=i+1;j<n;j++){
              int c2=colors[j];
              if(c1!=c2){
                maxi=max(maxi,j-i);
              }
            }
        }

        return maxi;
    }
};