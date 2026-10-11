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
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr) return true;
        queue<pair<TreeNode*, TreeNode*>>levels;
        levels.push({root->left, root->right});
        while(!levels.empty()){
                TreeNode* L = levels.front().first;
                TreeNode* R = levels.front().second;
                levels.pop();
                if(!L && !R) continue;
                if(!L || !R) return false;
                if(L->val != R->val) return false;
                levels.push({L->left, R->right});
                levels.push({L->right, R->left});
        }
        return true;
    }
};