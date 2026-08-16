class Solution {
public:
    int mySqrt(int x) {
        int l=1, r=x;
        while(l<=r) {
            int m = l + (r-l)/2;
            if (m > x/m) r = m-1;
            else if (m < x/m) l = m+1;
            else return m;
        }
        return r;
    }
};