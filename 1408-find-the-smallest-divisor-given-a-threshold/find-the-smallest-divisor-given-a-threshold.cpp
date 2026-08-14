class Solution {
private:
    int findMax(vector<int>& nums) {
        int maxi = INT_MIN;
        for (auto num:nums) maxi = max(maxi, num);
        return maxi;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int lo = 1, hi = findMax(nums);

        while (lo <= hi) {
            int mid = lo + (hi-lo)/2;
            int div = 0;
            for (auto num:nums) {
                // div += ceil((double)num / (double)mid);
                div += (num + mid - 1) / mid;
            }

            if (div <= threshold) hi = mid-1;
            else lo = mid+1;
        }
        return lo;
    }
};