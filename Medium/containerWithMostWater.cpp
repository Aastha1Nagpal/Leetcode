class Solution {
public:
    int maxArea(vector<int>& height) {
      int n = height.size();
      int l = 0;
      int r = n-1;
      int maxArea = 0;
      while(l<r){
        int w = r-l;
        int h = min(height[l], height[r]);
        int area = h*w;
        if(height[l]> height[r]){
            r--;
        }
        else{
            l++;
        }
        maxArea = max(area, maxArea);
      }
      return maxArea;
   }
};