# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right



class Solution:

    def __DFTHelp(self, curNode, depth):
        if curNode is None:
            return depth
        else:
            depthL = self.__DFTHelp(curNode.left, depth+1)
            depthR = self.__DFTHelp(curNode.right, depth+1)
            return max(depthL, depthR)

    def maxDepth(self, root: Optional[TreeNode]) -> int:
        depth = 0
        return self.__DFTHelp(root, depth)