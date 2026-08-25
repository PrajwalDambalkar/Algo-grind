class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int sum=0, ans=0;
        unordered_map<int, int> hmap;
        hmap[0] = 1;
        for (auto num:nums) {
            sum += num;
            if (hmap.find(sum-goal) != hmap.end()) ans += hmap[sum-goal];
            hmap[sum]++;
        }
        return ans;
    }
    //     cout<<atMost(nums, goal)<<"\n";
    //     cout<<atMost(nums, goal-1)<<"\n\n";
    //     return atMost(nums, goal) - atMost(nums, goal-1);
    // }

    // int atMost (vector<int> &nums, int goal) {
    //     int tail=0, ans=0, curSum=0;

    //     for (int head=0; head<nums.size(); head++) {
    //         curSum += nums[head];
            
    //         while (curSum > goal && tail <= head) {
    //             curSum -= nums[tail];
    //             tail++;
    //         }
    //         ans += (head-tail+1);
    //     }
    //     return ans;
    // }
};