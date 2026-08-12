class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int lo=0, hi=nums.size()-1, mid;

        while (lo < hi) {
            mid = lo + (hi-lo)/2;
            if (nums[mid] < nums[mid+1]) {
                lo = mid+1;
            }
            else if (nums[mid] > nums[mid+1]) hi = mid;
            else return mid;
        }
        return lo;
    }
};