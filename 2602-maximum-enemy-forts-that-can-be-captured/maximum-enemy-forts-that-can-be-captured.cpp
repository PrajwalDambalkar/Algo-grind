class Solution {
public:
    int captureForts(vector<int>& forts) {
        int n = forts.size();
        int ans = 0;
        
        for (int start = 0, end = 0; start<n; start++) {
            if (forts[start]) {
                if (forts[end] == -forts[start]) ans = max(ans, start - end - 1);
                end = start;
            }
        }
        return ans;
    }
};