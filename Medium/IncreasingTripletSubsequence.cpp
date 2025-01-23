brute force: 

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i<n ; i++){
            for(int j = i+1; j<n; j++){
                for(int k = j+1; k<n; k++){
                    if(nums[i]<nums[j] && nums[j]< nums[k] && nums[i]<nums[k])
                    return true;
                }
            }
        }
        return false;
    }
};


better/optimal:

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        vector<int> left_arr(n, INT_MAX);
        vector<int> right_arr(n, INT_MIN);

        left_arr[0] = nums[0];
        for (int i = 1; i < n; i++) {
            left_arr[i] = min(left_arr[i - 1], nums[i]);
        }

        right_arr[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            right_arr[i] = max(right_arr[i + 1], nums[i]);
        }
        for (int i = 1; i < n - 1; i++) {
            if (left_arr[i - 1] < nums[i] && right_arr[i + 1] > nums[i]) {
                return true;
            }
        }
        return false;
    }
};