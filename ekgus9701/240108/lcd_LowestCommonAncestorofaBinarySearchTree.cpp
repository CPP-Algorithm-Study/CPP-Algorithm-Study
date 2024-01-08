/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
          
          while (root) {
            if (root->val < p->val && root->val < q->val)
            //현재 노드의 값이 p, q보다 작다면 LCA는 우측 자식노드에 존재
                root = root->right;
            else if (root->val > p->val && root->val > q->val)
            //현재 노드의 값이 p, q보다 크다면 LCA는 좌측 자식노드에 존재
                root = root->left;
            else
                return root;
            }
        return NULL;

    }
};
