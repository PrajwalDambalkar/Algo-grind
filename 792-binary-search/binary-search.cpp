class Solution {
public:
    int search(vector<int>& nums, int target) {
        // linear
        // int n=nums.size();

        // if (target<nums[0] || target>nums[n-1]) return -1;
        // for (int i=0; i<n; i++) {
        //     if (nums[i] == target) return i;
        // }
        // return -1;

        int n = nums.size();
        int lo=0, hi=n-1, mid= (lo+hi) / 2;
        while (lo<=hi) {
            if (nums[mid] == target) return mid;
            else if (target < nums[mid]) {
                hi = mid-1;
                mid = (lo+hi)/2;
            }
            else if (target > nums[mid]) {
                lo = mid+1;
                mid = (lo+hi)/2;
            }
        }
        return -1;
    }
};