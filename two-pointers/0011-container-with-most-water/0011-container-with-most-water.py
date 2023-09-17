from typing import List

class Solution:
    def maxArea(self, height: List[int]) -> int:
        
        # solution by kshatriyas
        left = 0
        right = len(height) - 1
        maxArea = 0
        
        while left < right:
            currentArea = min(height[left], height[right]) * (right-left)
            maxArea = max(maxArea, currentArea)

            if height[left] < height[right]:
                left +=1
            else:
                right -= 1
        return maxArea

        ## O(N^2) - Time limit error
        # maxArea = -1
        # for i in range(len(height)):            
        #     for j in range(i+1, len(height)):
        #         maxArea = max(maxArea, (j-i)*min(height[i], height[j]))
        # return maxArea 