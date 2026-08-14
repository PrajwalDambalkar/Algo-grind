class Solution {
private:
    int findMax(vector<int>& nums) {
        int maxi = INT_MIN;
        for (auto num:nums) maxi = max(maxi, num);
        return maxi;
    }
    int add(vector<int>& nums) {
        int sum = 0;
        for (auto num:nums) sum += num;
        return sum;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int lo = findMax(weights), hi = add(weights);

        while (lo <= hi) {
            int mid = lo + (hi-lo)/2;
            int sum=0, cnt=0;

            for (auto x:weights) {
                sum += x;
                if (sum > mid) {
                    cnt++;
                    sum = x;
                }
            }
            if (cnt < days) hi = mid-1;
            else lo = mid+1;
        }
        return lo;
    }
};