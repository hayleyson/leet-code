class Solution(object):
    def longestSubarray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        # move i & increase count by 1 until hitting 0
        # after hitting 0, 
        # if last_delete_index is not None
        #    count = i - last_delete_index
        #    last_delete_index = i

        maxCount = count = 0
        last_delete_index = -1
        for i in range(len(nums)):
            if nums[i] == 1:
                count += 1
                if count > maxCount:
                    maxCount = count
            else:
                if last_delete_index == -1:
                    last_delete_index = i
                else:
                    count = i - last_delete_index - 1
                    last_delete_index = i
                    if count > maxCount:
                        maxCount = count
        if last_delete_index == -1:
            maxCount -= 1

        return maxCount
        