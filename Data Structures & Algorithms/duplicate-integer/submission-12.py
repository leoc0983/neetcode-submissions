class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        the_map = dict()
        for num in nums:
            if num not in the_map:
                the_map[num] = 0
            the_map[num] += 1
        for num in nums:
            if the_map[num] > 1:
                return True
        return False