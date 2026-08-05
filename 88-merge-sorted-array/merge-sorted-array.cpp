class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m-1, p2 = n-1, p3 = m+n-1;
        int i=0;
        while (p1>=0 && p2>=0) {
            if (nums1[p1] >= nums2[p2]) {
                nums1[p3] = nums1[p1];
                // nums1[p1] = 0;
                p1--;
                // p3--;
            }
            else if (nums1[p1] < nums2[p2]) {
                nums1[p3] = nums2[p2];
                p2--;
                // p3--;
            }
            p3--;
            // else {
            //     nums1[p3] = nums2[p2];
            //     // nums1[p3-1] = nums1[p1];
            //     p3--;
            //     p2--;
            //     p1--;
            // }
        }
        while (p2>=0) {
            nums1[p3] = nums2[p2];
            p3--;
            p2--;
        }
    }
};