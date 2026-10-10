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
    int minDiffInBST(TreeNode* root) {
        int temp, diff = INT_MAX, i = 0;
        Tree(root,temp,diff,i);
        return diff;
    }
    void Tree(TreeNode *root, int &temp, int &diff, int&i){
        if(root == nullptr) return;
        Tree(root->left,temp,diff,i);
        if(i == 0){
            temp = root->val;
            i++;
        }
        else{
            if((root->val-temp) < diff) diff = root->val - temp;
            temp = root->val;
        }
        Tree(root->right,temp,diff,i);
    }
};