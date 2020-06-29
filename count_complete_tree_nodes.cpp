/*

Given a complete binary tree, count the number of nodes.

Note:

Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

Example:

Input: 
    1
   / \
  2   3
 / \  /
4  5 6

Output: 6

*/

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
    int count = 0;
    void util(TreeNode* root) {
        if (root == nullptr) return;
        ++count;
        if (root->left) util(root->left);
        if (root->right) util(root->right);
    }
public:
    /*int countNodes(TreeNode* root) {
        util(root);
        return count;
    }*/
    int countNodes(TreeNode* root) {
        if (root == nullptr) return 0;
        int hl = 0, hr = 0;
        TreeNode *r = root;
        TreeNode *l = root;
        while(l) {
            ++hl;
            l = l->left;
        }
        while(r) {
            ++hr;
            r = r->right;
        }
        if (hl == hr) return (1<<hl)-1;
        return 1 + countNodes(root->left)  + countNodes(root->right);
    }
};