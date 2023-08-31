class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        tmpSum = sum(nums[:k])
        maxSum = tmpSum
        for i in range(0, len(nums)-k):
            tmpSum = tmpSum-nums[i]+nums[i+k]
            maxSum = max(maxSum, tmpSum)
        return maxSum/k