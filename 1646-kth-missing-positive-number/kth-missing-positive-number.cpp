class Solution {
private:
    int maxi(vector<int>& arr) {
        int ans = INT_MIN;
        for (auto a:arr) ans = max(ans, a);
        return ans;
    }
public:
    int findKthPositive(vector<int>& arr, int k) {
        // int lo = 1, hi = maxi(arr);

        // while(lo<=hi) {
        //     int mid = lo + (hi-lo)/2;
        //     int cnt = 0;
        //     for (auto a:arr) {
        //         if (a == )
        //     }
        // }
        for (auto a:arr) {
            if (a <= k) k++;
            else break;
        }
        return k;
    }
};