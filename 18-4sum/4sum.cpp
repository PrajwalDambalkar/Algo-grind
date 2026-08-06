class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n=nums.size();
        sort(nums.begin(), nums.end()); //nlogn
        // set<vector<int>> st;
        
        for (int i=0; i<n-3; i++) { //n
            if (i>0 && nums[i] == nums[i-1]) continue;

            for (int j=i+1; j<n-2; j++) { //n
                if (j>i+1 && nums[j] == nums[j-1]) continue;

                int l = j+1, r = n-1;

                while (l<r) {
                    long long int num = (long long)nums[i] + nums[j] + nums[l] + nums[r];
                    if (num == target) {
                        ans.push_back({nums[i], nums[j], nums[l], nums[r]});
                        while (l<r && nums[l] == nums[l+1]) l++;
                        while (l<r && nums[r] == nums[r-1]) r--;
                        l++;
                        r--;
                    }
                    else if (num < target) l++;
                    else r--;
                }
            }
        }

        if (nums.size() < 4) return {};

        return ans;
    }
};