class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size(), maxlen = 0;
        unordered_map<int, int> hashmap;
        int l=0, r=0;

        while (r<n) {
            hashmap[fruits[r]]++;
            while(hashmap.size() > 2) {
                hashmap[fruits[l]]--;
                if (hashmap[fruits[l]] == 0) hashmap.erase(fruits[l]);
                l++;
            }
            maxlen = max(maxlen, r-l+1);
            r++;
        }
        return maxlen;
    }
};