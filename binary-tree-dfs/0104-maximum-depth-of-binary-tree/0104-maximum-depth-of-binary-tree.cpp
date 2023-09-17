/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int __DFTHelp(TreeNode* curNode, int depth){
        if (curNode == nullptr){
            return depth;
        } else {
            int depthL = __DFTHelp(curNode->left, depth+1);
            int depthR = __DFTHelp(curNode->right, depth+1);
            return max(depthL, depthR);
        }
    }


    int maxDepth(TreeNode* root) {
        return __DFTHelp(root, 0);
    }
};
