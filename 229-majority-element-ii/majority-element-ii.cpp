class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
    
        // int n=nums.size();
        // int count=0, candidate1, candidate2;
        // vector<int> ans;

        // for (int i=0; i<n; i++) {
        //     if (count == 0) {
        //         candidate1 = nums[i];
        //         count++;
        //     }
        //     else if (candidate1 == nums[i]) {
        //         count++;
        //     }
        //     else if (candidate2 == nums[i]) {
        //         count++;
        //     }
        //     else if (candidate1 != candidate2)
        // }

        // return ans;

        int count1 = 0, count2 = 0, c1 = 0, c2 = 0;
        int n = nums.size();
        vector<int> ans;

        for (int i=0; i<n; i++) {
            if (count1 == 0 && c2 != nums[i]) {
                c1 = nums[i];
                count1 = 1;
            }
            else if (count2 == 0 && c1 != nums[i]) {
                c2 = nums[i];
                count2 = 1;
            }
            else if (c1 == nums[i]) count1++;
            else if (c2 == nums[i]) count2++;
            else {
                count1--;
                count2--;
            }
        }

        int cnt1 = 0, cnt2 = 0;
        for (int i=0; i<n; i++) {
            if (nums[i] == c1) cnt1++;
            else if (nums[i] == c2) cnt2++;
        }

        if (cnt1 > (n/3)) ans.push_back(c1);
        if (cnt2 > (n/3)) ans.push_back(c2);

        return ans;
    }
};