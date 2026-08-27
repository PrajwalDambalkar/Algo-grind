class Solution {
public:
    int maxNonAdjacentSum(vector<int> temp) {
        int n = temp.size();
        int prev = temp[0];
        int prev2 = 0;
        for (int i=0; i<n; i++) {
            int curr = temp[i];
            if (i>1) curr += prev2;

            int notCurr = 0 + prev;
            int current = max(curr, notCurr);
            prev2 = prev;
            prev = current;
        }
        return prev;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp1, temp2;
        if (n==1) return nums[0];

        for (int i=0; i<n; i++) {
            if (i != 0) temp1.push_back(nums[i]);
            if (i != n-1) temp2.push_back(nums[i]);
        }
        return max(maxNonAdjacentSum(temp1), maxNonAdjacentSum(temp2));
    }
};