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
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) {
            return true; // 빈 트리는 항상 균형이 잡혀 있다고 가정
        }

        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);

        // 높이 차이가 1 이상인 경우 균형이 깨짐
        if (abs(leftHeight - rightHeight) > 1) {
            return false;
        }

        // 좌우 서브트리가 각각 균형이 잡혀 있어야 함
        return isBalanced(root->left) && isBalanced(root->right);
    }

private:
    int getHeight(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }

        int leftHeight = getHeight(node->left);
        int rightHeight = getHeight(node->right);

        return max(leftHeight, rightHeight) + 1;
    }
};
