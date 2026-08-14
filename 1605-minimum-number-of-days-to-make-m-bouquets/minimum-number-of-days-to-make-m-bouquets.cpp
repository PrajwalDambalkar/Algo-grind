class Solution {
private:
    // int mini(vector<int>& bloomDay) {
    //     int lo = INT_MAX;
    //     for (auto bloom:bloomDay) {
    //         lo = min(lo, bloom);
    //     }
    //     return lo;
    // }

    int maxi(vector<int>& bloomDay) {
        int hi = INT_MIN;
        for (auto bloom:bloomDay) {
            hi = max(hi, bloom);
        }
        return hi;
    }

    // bool possible(vector<int>& bloomDay, int d, int m, int k) {
    //     int cnt = 0;
    //     int nofB = 0;
    //     for (auto bloom:bloomDay) {
    //         if (bloom <= d) {
    //             cnt++; 
    //         }
    //         else {
    //             nofB += cnt/k;
    //             cnt = 0;
    //         }
    //     }
    //     nofB += cnt/k;

    //     return nofB >= m;
    // }

public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int lo = 0, hi = maxi(bloomDay);
        // int ans = hi;
        if (bloomDay.size() < (long long)m*k) return -1;

        while (lo <= hi) {
            int mid = lo + (hi-lo)/2;
            int cnt=0, bq=0;
            for (int i=0; i<bloomDay.size(); i++) {
                if (bloomDay[i] <= mid) cnt++;
                else cnt = 0;
                if (cnt == k) {
                    bq++;
                    cnt = 0;
                }
            }
            if (bq >= m) {
                hi = mid-1;
            }
            else lo = mid+1;
            // if (possible(bloomDay, mid, m, k)) {
            //     ans = mid;
            //     hi = mid-1;
            // }
            // else lo = mid+1;
        }
        return lo;
    }
};