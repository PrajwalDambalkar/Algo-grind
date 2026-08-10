class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        int sum = 0, ans = 0;
        map[sum] = 1;

        for (auto num:nums) {
            sum += num;
            if (map.find(sum - k) != map.end()) {
                ans += map[sum - k];
            }
            map[sum]++;
        }
        return ans;


        // //bruteforce
        // int ans = 0;

        // for(int i=0; i<nums.size(); i++) {
        //     int sum = nums[i];
        //     if (sum == k) ans++;

        //     for (int j=i+1; j<nums.size(); j++) {
        //         sum += nums[j];
        //         if (sum == k) {
        //             ans++;
        //         }
        //     }
        // }

        // return ans;
    }
};