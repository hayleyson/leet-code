class Solution(object):
    def largestAltitude(self, gain):
        """
        :type gain: List[int]
        :rtype: int
        """
        maxAlt=0
        alt=0
        for i in range(len(gain)):
            alt += gain[i]
            if alt > maxAlt:
                maxAlt = alt
        return maxAlt
        