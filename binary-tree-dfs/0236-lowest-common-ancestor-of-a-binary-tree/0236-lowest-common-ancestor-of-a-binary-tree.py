# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:

    def __DFTHelp(self, curNode, p, q):
        if curNode is None:
            return False, None
        else:
            
            resSelf = (curNode.val in [p.val, q.val])
            resL, retNodeL = self.__DFTHelp(curNode.left, p, q)
            resR, retNodeR = self.__DFTHelp(curNode.right, p, q)

            if retNodeL: # if LCA is already found.
                return True, retNodeL
            elif retNodeR:
                return True, retNodeR
            else:
                trueCount = sum([resSelf, resL, resR])
                if trueCount == 2: # if two of the above conditions are true.
                    return True, curNode
                elif trueCount == 1: # if only one is met.
                    return True, None
                else: # if none is met.
                    return False, None
            
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        return self.__DFTHelp(root, p, q)[1]