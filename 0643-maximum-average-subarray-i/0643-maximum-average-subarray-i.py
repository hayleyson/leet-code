class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        # added after looking at solution by deepankyadav
        if len(nums)==1:
            return nums[0]
        
        # my solution
        tmpSum = sum(nums[:k])
        maxSum = tmpSum
        for i in range(0, len(nums)-k):
            tmpSum = tmpSum-nums[i]+nums[i+k]
            maxSum = max(maxSum, tmpSum)
        return maxSum/k