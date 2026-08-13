class Solution {
public:
    int findMin(vector<int>& nums) {
        int lo=0, hi=nums.size()-1;
        int mid, mini=INT_MAX;

        while (lo <= hi) {
            mid = lo + (hi-lo)/2;

            // if (nums[lo] <= nums[mid] && nums[mid] <= nums[hi]) return lo;

            if (nums[lo] <= nums[mid]) {
                mini = min(mini, nums[lo]);
                lo = mid+1;
            }
            else {
                hi = mid-1;
                mini = min(nums[mid], mini);
            } 
        }
        return mini;
    }
};