class Solution {
public:
    int maxArea(vector<int>& height) {
       int n=height.size();
       int maxi=0;
       int left=0;
       int right=n-1;
       while(left<right){
        int width=(right-left);
        int h=min(height[left],height[right]);
        int volume=width*h;
        maxi=max(maxi,volume);
        if(height[left]<height[right]){
            left++;
        }else{
            right--;
        }
       }
       return maxi; 
    }
};