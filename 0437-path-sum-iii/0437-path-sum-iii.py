# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:

    """solution by wonderlives 1. brute force
    memory O(1), time O(N^2) or O(NlogN)
    # ---
    
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
    """

    """solution by wonderlives 2. memorization
    memory O(N), time O(N)
    """
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> int:
        self.result = 0 
        cache={0:1}
        self.dfs(root,targetSum,0,cache) 
        return self.result

    def dfs(self, node, target, currPathSum, cache):
        if node is None: # base case
            return
        
        currPathSum += node.val
        oldPathSum = currPathSum - target
        self.result += cache.get(oldPathSum, 0)
        cache[currPathSum] = cache.get(currPathSum, 0) + 1

        self.dfs(node.left, target, currPathSum, cache)
        self.dfs(node.right, target, currPathSum, cache)

        cache[currPathSum] -= 1