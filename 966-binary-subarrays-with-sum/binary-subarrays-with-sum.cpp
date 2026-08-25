class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        cout<<atMost(nums, goal)<<"\n";
        cout<<atMost(nums, goal-1)<<"\n\n";
        return atMost(nums, goal) - atMost(nums, goal-1);
    }

    int atMost (vector<int> &nums, int goal) {
        int tail=0, ans=0, curSum=0;

        for (int head=0; head<nums.size(); head++) {
            curSum += nums[head];
            
            while (curSum > goal && tail <= head) {
                curSum -= nums[tail];
                tail++;
            }
            ans += (head-tail+1);
        }
        return ans;
    }
};