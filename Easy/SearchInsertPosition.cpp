class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int r = n-1;
        int mid;
        // int mid = l + (r-l)/2;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(nums[mid] == target){
                return mid;
            }
            if(nums[mid]> target){
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return l;
    }
};