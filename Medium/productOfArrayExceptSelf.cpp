Brute force approach:(TLE)

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        int p;
        for(int i = 0; i<n; i++){
            p = 1;
            for(int j = 0; j<n; j++){
                if(i!=j){
                    p *= nums[j];
                }
            }
            res.push_back(p);
        }
        return res;
    }
};

Better:

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        int p = 1;
        int zeroCount = 0;
        // int ans;
        for(int i = 0; i<n; i++){
            if(nums[i] == 0){
                zeroCount++;
            }
            else
            p*= nums[i];
        }
        for(int i = 0; i<n; i++){
             if(zeroCount == 1){
                if (nums[i] == 0) res.push_back(p);   
                else res.push_back(0);
            }
           else if(zeroCount> 1){
                res.push_back(0);
            }
            else res.push_back(p/nums[i]);
        }
        return res;
    }
};