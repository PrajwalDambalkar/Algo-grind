class Solution {
private:
    int findMax(vector<int>& piles) {
        int maxi = INT_MIN;
        for (int i=0; i<piles.size(); i++) {
            maxi = max(maxi, piles[i]);
        }
        return maxi;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 1, hi = findMax(piles);
        int ans = hi;

        while (lo <= hi) {
            int mid = lo + (hi-lo)/2;
            long long totalH = 0;
            for (int i=0; i<piles.size(); i++) {
                totalH += ((long long)piles[i] + mid-1) / mid;
            }

            if (totalH <= h) {
                // ans = mid;
                hi = mid-1;
            }
            else lo = mid+1;
        }

        return lo;
    }
};