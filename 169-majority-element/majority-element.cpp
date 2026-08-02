class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans;
        unordered_map<int, int> map;
        int n = nums.size();
        
        for (int i=0; i<n; i++) {
            map[nums[i]]++;

        }

        for (auto x:map) {
            if (x.second > (n/2)) return x.first;
        }

        return 0;
    }
};