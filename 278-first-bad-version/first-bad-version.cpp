// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
// private:
//     bool isBadVersion(int version) {

//     }
public:
    int firstBadVersion(int n) {
        long long int lo=1, hi=n, mid, ans;
        if (n==1 && isBadVersion(lo)) return n;
        while (lo<=hi) {
            mid = (lo+hi)/2;
            if (isBadVersion(mid)) {
                ans = mid;
                hi = mid - 1;
            }
            else lo = mid + 1;
        }
        return ans;
    }
};