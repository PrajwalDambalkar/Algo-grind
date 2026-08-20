class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size(), maxlen = 0;
        vector<int> hashmap(256, -1);
        int l=0, r=0;

        while (r<n) {
            if (hashmap[s[r]] != -1) l = max(l, hashmap[s[r]]+1);
            hashmap[s[r]] = r;
            maxlen = max(maxlen, r-l+1);
            r++;
        }
        return maxlen;


        // Bruteforce On^2;
        // int maxlen = 0;
        // for (int i=0; i<n; i++) {
        //     vector<int> hashmap(256, 0);
        //     for (int j=i; j<n; j++) {
        //         if (hashmap[s[j]] == 1) break;
        //         hashmap[s[j]] = 1;
        //         maxlen = max(maxlen, j-i+1);
        //     }
        // }
        // return maxlen;
    }
};