class Solution(object):
    def longestSubarray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        # maxCount = count = 0
        # delete_index = -1
        # for i in range(len(nums)):
        #     if nums[i] == 1: # pass 1's
        #         count += 1
        #     else:   # if encounter 0
        #         if delete_index == -1: # if it's first time encountering
        #             delete_index = i
        #         else: # if it already had encountered 0
        #             count = i - delete_index - 1
        #             delete_index = i
        #     if count > maxCount:
        #         maxCount = count
        # if delete_index == -1: # if all elems are 1's. Remove one 1 -> decrease maxCount by 1.
        #     maxCount -= 1

        # return maxCount

        ## solution by shivam-727
        i, j = 0, 0
        mx = 0
        c0 = 0
        n = len(nums)

        while(j < n):
            if nums[j] == 0:
                c0 += 1
            while (i < n and c0 == 2):
                if nums[i] == 0:
                    c0 -= 1
                i+= 1
            mx = max(mx, j - i)
            j += 1
        return mx
        