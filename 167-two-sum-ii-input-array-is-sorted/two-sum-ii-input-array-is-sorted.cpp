class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans();
        int n = numbers.size();
        int j = n-1;
        int i=0;
        while (i<j) {
            if (numbers[i]+numbers[j] == target) {
                return {i+1, j+1};
            }
            else if (numbers[i]+numbers[j] < target) i++;
            else j--;
        }
        return {};
    }
};