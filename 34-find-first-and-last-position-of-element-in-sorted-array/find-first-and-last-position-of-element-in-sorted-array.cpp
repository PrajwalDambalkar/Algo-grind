class Solution {
private:
    int lowerBound(vector<int>& nums, int target) {
        int n = nums.size();
        int lo = 0, hi = n-1, mid;
        int ans = n;

        while(lo<=hi) {
            mid = (lo+hi)/2;
            if (nums[mid] >= target) {
                ans = mid;
                hi = mid - 1;
            }
            else lo = mid + 1;
        }
        return ans;
    }

    int upperBound(vector<int>& nums, int target) {
        int n = nums.size();
        int lo = 0, hi = n-1, mid;
        int ans = n;

        while(lo<=hi) {
            mid = (lo+hi)/2;
            if (nums[mid] > target) {
                ans = mid;
                hi = mid - 1;
            }
            else lo = mid + 1;
        }
        return ans;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        
        int lowb = lowerBound (nums, target);

        if (lowb == nums.size() || nums[lowb] != target) return {-1, -1};

        return {lowb, upperBound(nums, target) - 1};
        
        //Bruteforce but not allowed

        // int first = -1, last = -1;
        // for (int i=0; i<n; i++) {
        //     if (nums[i] == target) {
        //         if (first == -1) first = i;
        //         last = i;
        //     }
        // }

        // while (lo<=hi) {

        //     int mid = (lo+hi)/2;

        // }
        // return {first, last};
    }
};