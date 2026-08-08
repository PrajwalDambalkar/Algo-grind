class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi = INT_MIN, n = nums.size(); 
        int prod = 1;
        int mini = INT_MAX;
        // if (nums.size() == 1) return nums[0];

        for (int i=0; i<n; i++) {
            prod *= nums[i];
            maxi = max(maxi, prod);
            if (prod == 0) prod=1;
        }
        prod = 1;

        for (int i=n-1; i>=0; i--) {
            prod *= nums[i];
            maxi = max(prod, maxi);
            if (prod == 0) prod = 1;
        }

        return maxi;
    }
};