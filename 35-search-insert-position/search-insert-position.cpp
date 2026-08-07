class Solution {
private:
    // int posIndex (vector<int>& nums, int target, int lo, int hi) {
    //     if (lo == hi)
    // }
public:
    int searchInsert(vector<int>& nums, int target) {
        int lo=0, n=nums.size();
        int hi = n-1;
        int mid;

        while (lo <= hi) {
            mid = (lo + hi)/2;
            if (nums[mid] == target) return mid;
            if (nums[mid] > target) {
                hi = mid-1;
            } else if (nums[mid] < target) {
                lo = mid+1;
            }
        }

        return lo;
    }
};