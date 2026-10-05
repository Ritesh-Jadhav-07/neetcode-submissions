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

    int height(TreeNode* root){
        if(root == NULL) return 0;

        auto l = height(root->left);
        auto r = height(root->right);

        return 1 + max(l,r);
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        if(root->left == NULL && root->right == NULL) return true;
        auto l = height(root->left);
        auto r = height(root->right);

        bool flag = abs(l-r) <= 1 ? true : false;

        auto lp = isBalanced(root->left);
        auto rp = isBalanced(root->right);

        return flag && lp && rp;

    }
};
