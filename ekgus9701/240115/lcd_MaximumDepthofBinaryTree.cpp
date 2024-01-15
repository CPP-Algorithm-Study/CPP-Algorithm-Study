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
    int maxnum=1;
   
    void find(TreeNode* root, int cnt){
         if(root!=nullptr) maxnum=max(maxnum,cnt);
         if(root->left!=nullptr){
            find(root->left,cnt+1);
         }
         if(root->right!=nullptr){
            find(root->right,cnt+1);
         }
    }

    int maxDepth(TreeNode* root) {
        if(root==nullptr) return 0;
        
        find(root,1);

        return maxnum;
        
    }
};
