class Solution {
public:
    int rob(vector<int>& nums) {
        // long long int maxi1 = 0, maxi2 = 0;
        
        // for (int i=0; i<nums.size(); i+=2) {
        //     maxi1 += nums[i];
        // }

        // for (int i=1; i<nums.size(); i+=2) {
        //     maxi2 += nums[i];
        // }

        // return max(maxi1, maxi2);
        int prev2 = 0, prev1 = 0;
        for (int num : nums) {
            int curr = max(prev1, prev2 + num);
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};