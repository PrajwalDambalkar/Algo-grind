class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int j=0, odd=0, cnt=0, ans=0;
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] & 1) {
                odd++;
                if (odd >= k) {
                    cnt = 1;
                    while (!(nums[j++] & 1)) cnt++;
                    ans += cnt;
                }
            }
            else if (odd >= k) ans += cnt;
        }
        return ans;
    }
};