# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:

    """solution by wonderlives 1. brute force"""
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> int:
        self.result = 0 #  instead of using global scope, declared result as an attribute of Solution class -> shared across multiple function calls
        self.dfs(root,targetSum) 
        return self.result

    def dfs(self, node, target):
        if node is None: # base case
            return
        
        self.test(node, target) # inner dfs that checks if paths starting from this node has path sum equal to target
        self.dfs(node.left, target) # dfs into the left branch
        self.dfs(node.right, target) # dfs into the right branch

    def test(self, node, target):
        if node is None:
            return
        if node.val == target:
            self.result += 1
        
        # check if path sums starting from this node excluding this node's value equals to target-node.val
        self.test(node.left, target-node.val)
        self.test(node.right, target-node.val)