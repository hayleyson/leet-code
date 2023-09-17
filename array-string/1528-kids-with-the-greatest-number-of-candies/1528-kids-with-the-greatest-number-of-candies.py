from typing import List

class Solution:
    def kidsWithCandies(self, candies: List[int], extraCandies: int) -> List[bool]:
        # if already max => always yes
        # if not already max => check diff between max => if diff is same as or smaller than extraCandies, yes / if not no.
        result = []
        max_candy = max(candies)
        for i in range(len(candies)):
            if (candies[i] == max_candy) or ((max_candy - candies[i]) <= extraCandies):
                result.append(True)
            else:
                result.append(False)
        return result