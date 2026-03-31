class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        ## Bruteforce

        # for i in range(len(nums)):
        #     for j in range(i+1, len(nums)):
        #         if nums[i] == nums[j]:
        #             return True
        # return False

        ## Sorting O(nlog(n))
        # nums.sort()
        # for i in range(1, len(nums)):
        #     if nums[i] == nums[i-1]:
        #         return True
        
        # return False

        ## Hashset
        # seen = set()
        # for num in nums:
        #     if num in seen:
        #         return True
        #     seen.add(num)
        
        # return False

        return len(nums) != len(set(nums))