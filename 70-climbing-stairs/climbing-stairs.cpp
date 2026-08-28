class Solution {
public:
    int climbStairs(int n) {
        // vector<int> dp(n+1, -1);
        // return solve(n, dp);

        vector<int> dp(n+1);
        dp[0] = 1;
        dp[1] = 1;

        for (int i=1; i<n; i++) {
            int sum = 0;
            if (i-1 >= 0) sum+=dp[i-1];
            if (i-2 >= 0) sum+=dp[i-2];
            dp[i] += sum;
        }
        return dp[n-1];
    }

    // int solve(int n, vector<int> &dp) {
    //     if(n <= 2) return n;

    //     if (dp[n] != -1) return dp[n];

    //     return dp[n] = solve(n-1, dp) + solve(n-2, dp);
    // }
};