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

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==nullptr) return ans;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            vector<int> temp;
            int qsize=q.size();
            

            for(int i=0;i<qsize;i++){
                TreeNode* curN=q.front();
                q.pop();
                temp.push_back(curN->val);
                if(curN->left) q.push(curN->left);
                if(curN->right) q.push(curN->right);

            }
            ans.push_back(temp);
           
        }


        return ans;

        

        
        
    }
};
