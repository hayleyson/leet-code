class Solution(object):
    def longestSubarray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        # move i & increase count by 1 until hitting 0
        # when hitting 0, 
        # if delete_index is not set (first time encountering 0)
        #    count = i - delete_index - 1
        #    delete_index = i
        # else
        #    count = count
        #    delete_index = i
        # maxCount = max(count, maxCount)

        maxCount = count = 0
        delete_index = -1
        for i in range(len(nums)):
            if nums[i] == 1: # pass 1's
                count += 1
            else:   # if encounter 0
                if delete_index == -1: # if it's first time encountering
                    delete_index = i
                else: # if it already had encountered 0
                    count = i - delete_index - 1
                    delete_index = i
            if count > maxCount:
                maxCount = count
        if delete_index == -1: # if all elems are 1's. Remove one 1 -> decrease maxCount by 1.
            maxCount -= 1

        return maxCount
        