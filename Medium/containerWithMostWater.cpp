brute force: 

class Solution {
public:
    int maxArea(vector<int>& height) {
       int n = height.size();
       int maxArea = 0;
       for(int i = 0; i<n; i++){
        for(int j = i+1; j<n ; j++){
            int width = j-i;
            int area = width* min(height[i], height[j]);
            maxArea = max(maxArea, area);
        }
       }
       return maxArea; 
    }
};

optimal solution:

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